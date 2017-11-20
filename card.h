#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPushButton>

class Card : public QPushButton
{
    Q_OBJECT
public:
    explicit Card(QPushButton*);
    void select();
    void deSelect();
    void turn();
    void unTurn();
    int getState(); //-1 = flipped, 0 = not selected, 1 = selected
    int getNum();
    void setNum(int);
signals:

public slots:

private:
    int state;
    int num;
};

#endif // CARD_H
