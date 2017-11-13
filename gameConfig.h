#ifndef NEWGAME_H
#define NEWGAME_H
#include <QWindow>
#include "ui_gameconfig.h"
#include <QWidget>
#include "mainwindow.h"


class GameConfig : public QWidget
{
    Q_OBJECT

public:
    explicit GameConfig(QWidget *parent = 0);
    ~GameConfig();

private:
    Ui::GameConfig *ui;
public slots:
    void on_select_easy();
    void on_select_medium();
    void on_select_hard();
};

#endif // NEWGAME_H
