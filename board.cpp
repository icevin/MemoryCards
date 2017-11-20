#include "board.h"
#include "card.cpp"
#include "rules.h"
#include <QMainWindow>
#include <QThread>
#include <algorithm>
#include <string>
Board::Board(int time, int cardRows, int cardCols, MainWindow* p)
{
    parent = p;
    unturn = ".";
    turn = 0;
    moves = 0;
    prevr = 0;
    prevc = 0;
    disp = 1;
    points = 0;
    wins = 0;
    lock = 0;
    pMultiplier = (cardRows * cardCols*20)/(time);
    req = (cardRows * cardCols)/2;

    this->setStyleSheet("background-color: rgb(247,247,247)");
    this->setWindowTitle(QStringLiteral("Initializing..."));
    this->setMaximumSize(800, 800);

    QFont font;
    font.setPointSize(36);
    font.setWeight(75);

    QFont menuFont;
    menuFont.setPointSize(24);
    menuFont.setWeight(50);

    QFont numFont;
    numFont.setPointSize(24);
    numFont.setWeight(25);

    bvLayout = new QVBoxLayout(this);
    bvLayout->setObjectName(QStringLiteral("vertLayout"));

    space = new QHBoxLayout();

    bLayout = new QGridLayout(this);
    bLayout->setHorizontalSpacing(10);
    bLayout->setVerticalSpacing(10);

    menu = new QVBoxLayout();
    menu->setObjectName(QStringLiteral("menu"));
    menu->addSpacing(20);
    menu->addSpacing(20);

    timer = new QLabel("Initializing...");
    timer->setObjectName(QStringLiteral("timerLabel"));
    timer->setFont(font);
    timer->setScaledContents(false);
    timer->setAlignment(Qt::AlignCenter);
    bvLayout->addWidget(timer);

    board.resize(cardRows);
    for(int i = 0; i < cardRows; i++)
        board.at(i).resize(cardCols);

    vector<int> pairs;
    int pairmap = 0;
    for(int i = 0; i < req; i++) {
        pairs.push_back(i);
        pairs.push_back(i);
    }
    std::random_shuffle(pairs.begin(),pairs.end());

    for(int i = 0; i<cardRows; i++)
        for(int j = 0; j<cardCols; j++) {
            board[i][j] = new Card(new QPushButton);
            board[i][j]->setObjectName(QString::number(i) + QStringLiteral(",") + QString::number(j));
            board[i][j]->setText(QStringLiteral(""));
            board[i][j]->setStyleSheet("background-color: rgba(108, 122, 137, 100%); color: rgb(0, 0, 0)");
            if(std::stoi(parent->options.substr(0,1)) == 1) {
                board[i][j]->setText(QString::number(pairs[pairmap]));
            }
            board[i][j]->setNum(pairs[pairmap]);
            pairmap++;
            bLayout->addWidget(board[i][j],1+i,1+j,1,1,Qt::AlignCenter);
            bLayout->setAlignment(board[i][j], 0);
            connect(board[i][j], &QPushButton::released, this, [this,i,j]{this->cardSelect(i,j);});
        }

    pointD = new QLabel("Points: ");
    pointD->setObjectName(QStringLiteral("pointD"));
    pointD->setFont(menuFont);
    pointD->setScaledContents(true);
    pointD->setAlignment(Qt::AlignCenter);
    menu->addWidget(pointD);

    pointN = new QLabel;
    pointN->setObjectName(QStringLiteral("pointN"));
    pointN->setFont(numFont);
    pointN->setScaledContents(true);
    pointN->setAlignment(Qt::AlignCenter);
    menu->addWidget(pointN);

    movesD = new QLabel("Moves: ");
    movesD->setObjectName(QStringLiteral("movesD"));
    movesD->setFont(menuFont);
    movesD->setScaledContents(true);
    movesD->setAlignment(Qt::AlignCenter);
    menu->addWidget(movesD);

    movesN = new QLabel;
    movesN->setObjectName(QStringLiteral("movesN"));
    movesN->setFont(numFont);
    movesN->setScaledContents(true);
    movesN->setAlignment(Qt::AlignCenter);
    menu->addWidget(movesN);

    selectHelp = new QPushButton(this);
    selectHelp->setObjectName(QStringLiteral("selectHelp"));
    selectHelp->setText(QStringLiteral("Rules"));
    selectHelp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    selectHelp->setFont(menuFont);
    connect(selectHelp, SIGNAL (released()), this, SLOT (on_select_help()));
    menu->addWidget(selectHelp);

    selectExit = new QPushButton(this);
    selectExit->setObjectName(QStringLiteral("selectExit"));
    selectExit->setText(QStringLiteral("Exit"));
    selectExit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    selectExit->setFont(menuFont);
    connect(selectExit, SIGNAL (released()), this, SLOT (on_select_exit()));
    menu->addWidget(selectExit);

    space->addLayout(bLayout);
    space->addLayout(menu);

    bvLayout->addLayout(space);

    timeLeft = time+1;
    t = new QTimer();
    t->start(1000);
    connect(t,SIGNAL(timeout()),this,SLOT(tick()));

    this->showMaximized();
}

void Board::tick() {
    timeLeft--;

    if(disp == 1) {
        timer->setText(QStringLiteral("Time remaining: ") + QString::number(timeLeft) + QStringLiteral("s"));
        pointN->setText(QString::number(points));
        movesN->setText(QString::number(moves));

        if(unturn != ".") {
            board[stoi(unturn.substr(0,1))][stoi(unturn.substr(1,1))]->unTurn();
            board[stoi(unturn.substr(2,1))][stoi(unturn.substr(3,1))]->unTurn();
            unturn = ".";
            lock = 0;
        }
    }
    if(disp) {
        disp = 1;
    } else {
        //parent->show();
        //this->close();
    }

    if(timeLeft > 0) {
        this->setWindowTitle(QStringLiteral("Time remaining: ") + QString::number(timeLeft) + QStringLiteral("s"));
    } else {
        endGame(0);
    }
}
void Board::on_select_help() {
    rules* r = new rules(parent, 0);
    r->show();
}

void Board::on_select_exit() {
    parent->show();
    this->close();
}

void Board::cardSelect(int row, int column) {
    if(board[row][column]->getState() == 0 && lock == 0 && disp) {
        board[row][column]->select();
        turn++;
        if(turn == 1) {
            prevr = row;
            prevc = column;
        }
        if(turn == 2) {
            moves++;
            board[row][column]->turn();
            board[prevr][prevc]->turn();
            movesN->setText(QString::number(moves));
            if(board[row][column]->getNum() == board[prevr][prevc]->getNum()) {
                disp = 2;
                timer->setText(QStringLiteral("Match!"));
                points += (float)(timeLeft) * 1.4352f * (float)(pMultiplier);
                if(stoi(parent->options.substr(0,1)) == 1) {
                    points *= 100;
                    timeLeft += 10;
                }
                pointN->setText(QString::number(points));
                wins++;
                if(wins == req) {
                    this->endGame(1);
                }
            } else {
                disp = 2;
                timer->setText(QStringLiteral(":("));
                lock = 1;
                unturn = std::to_string(row) + std::to_string(column) + std::to_string(prevr) + std::to_string(prevc);
            }
            turn = 0;
        }
    }
    else if(board[row][column]->getState() == 1) {
        board[row][column]->deSelect();
        turn--;
    }
}

void Board::endGame(int cond) {
    disp = 0;
    if(cond) {
        timer->setText(QStringLiteral("You win!"));
        points += (timeLeft*20*pMultiplier)-(moves*pMultiplier*10);
        pointN->setText(QString::number(points));
    } else {
        timer->setText(QStringLiteral("You lose! :("));
    }
}
