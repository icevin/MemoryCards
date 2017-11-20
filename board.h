#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtGui>
#include <QMainWindow>
#include "card.h"
#include "mainwindow.h"
#include <string>

using std::vector;

class MainWindow;

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    explicit Board(int time, int, int, MainWindow* parent);

    QLabel* timer;
    QLabel* pointD;
    QLabel* pointN;
    QLabel* movesD;
    QLabel* movesN;
    QTimer* t;
    QVBoxLayout* bvLayout;
    QGridLayout* bLayout;
    QVBoxLayout* menu;
    QHBoxLayout* space;
    vector<vector<Card*>> board;

    int timeLeft; //seconds remaining
    QPushButton* selectHelp;
    QPushButton* selectExit;
    MainWindow* parent;
public slots:
    void tick();
    void on_select_help();
    void on_select_exit();
    void cardSelect(int, int);
    void endGame(int);
private:
   // void updateLayout();
    int turn;
    int moves;
    int prevr;
    int prevc;
    int disp;
    int points;
    int wins;
    int req;
    int lock;
    int pMultiplier;
    std::string unturn;
};

#endif // BOARD_H
