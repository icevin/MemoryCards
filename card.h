#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPushButton>

class Card : public QPushButton
{
    Q_OBJECT
public:
    explicit Card(QPushButton*);
    void flip();
    int getState(); //-1 = flipped, 0 = not selected, 1 = selected
signals:

public slots:

private:
    int state;
};

#endif // CARD_H
