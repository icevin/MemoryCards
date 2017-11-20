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
#include "card.h"

using std::vector;

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    explicit Board(int time, int, int);
    int cardCount;
    QLabel* timer;
    QVBoxLayout* bvLayout;
    QGridLayout* bLayout;
    vector<vector<Card*>> board;
    QTimer* t;
    int timeLeft; //seconds remaining
public slots:
    void tick() {
       timeLeft--;
       this->setWindowTitle(QStringLiteral("Time remaining: ") + QString::number(timeLeft) + QStringLiteral("s"));
    }
    /*void cardSelect(int, int);
    void endGame();
    void restartGame();*/
private:
   // void updateLayout();
};

#endif // BOARD_H
