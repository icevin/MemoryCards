#include "board.h"
#include "card.cpp"
Board::Board(int time, int cardRows, int cardCols)
{
    timeLeft = time;
    this->showMaximized();
    this->setWindowTitle(QStringLiteral("Initializing..."));

    board.resize(cardRows);
    for(int i = 0; i < cardRows; i++) {
        board.at(i).resize(cardCols);
    }


    bvLayout = new QVBoxLayout(this);
    bvLayout->setObjectName(QStringLiteral("vertLayout"));

    bLayout = new QGridLayout(this);

    for(int i = 0; i<cardRows; i++)
    {
        for(int j = 0; j<cardCols; j++) {
            board[i][j] = new Card(new QPushButton);
            board[i][j]->setObjectName(QString::number(i) + QStringLiteral(",") + QString::number(j));
            board[i][j]->setText(QString::number(i) + QStringLiteral(",") + QString::number(j));
            board[i][j]->setAutoFillBackground(true);
            board[i][j]->setStyleSheet("background-color: rgb(108, 122, 137); color: rgb(108, 255, 137)");
            bLayout->addWidget(board[i][j],i,j,1,1,Qt::AlignCenter);
        }
    }

    bvLayout->addLayout(bLayout);

    t = new QTimer();
    t->start(1000);
    connect(t,SIGNAL(timeout()),this,SLOT(tick()));
}
