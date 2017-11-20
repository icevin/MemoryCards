#include "card.h"
#include <iostream>
Card::Card(QPushButton *parent) : QPushButton(parent)
{
    QSizePolicy p;
    p.setVerticalStretch(2);
    p.setHorizontalStretch(1.5);
    p.setWidthForHeight(true);
    p.setVerticalPolicy(QSizePolicy::Minimum);
    this->setAutoFillBackground(true);
    this->setSizePolicy(p);
    this->setMaximumWidth(100);
    this->setMaximumHeight(150);
    this->setMinimumHeight(100);

    QFont fonta;
    fonta.setPointSize(30);
    fonta.setBold(true);
    fonta.setWeight(75);
    this->setFont(fonta);
    state = 0;
    num = -1;
}

void Card::select() {
    state = 1;
    this->setStyleSheet("background-color: rgba(108,122,137,50%)");
    this->setText(QStringLiteral(""));
}

void Card::deSelect() {
    state = 0;
    this->setStyleSheet("background-color: rgba(108,122,137,100%)");
    this->setText(QStringLiteral(""));
}

void Card::turn() {
    this->setStyleSheet("background-color: rgba(0,0,0,0%)");
    this->setText(QString::number(num));
    state = -1;
}

void Card::unTurn() {
    this->setStyleSheet("background-color: rgba(108, 122, 137, 100%)");
    this->setText(QStringLiteral(""));
    state = 0;
}

int Card::getState() {
    return state;
}

int Card::getNum() {
    return num;
}

void Card::setNum(int n) {
    num = n;
}
