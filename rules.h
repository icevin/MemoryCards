#ifndef RULES_H
#define RULES_H

#include <QWidget>
#include "mainwindow.h"
class rules : public QWidget
{
    Q_OBJECT
public:
    explicit rules(MainWindow* p, int);

    QVBoxLayout* l;
    QLabel* title;
    QLabel* ruleL;
    QPushButton* back;
signals:

public slots:
    void on_back();
private:
    MainWindow* parent;
    int ab;
};

#endif // RULES_H
