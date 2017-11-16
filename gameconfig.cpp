/*#include "gameconfig.h"
#include "ui_gameconfig.h"

GameConfig::GameConfig(QWidget *parent) :
    QWidget(parent), ui(new Ui::GameConfig)
{
    ui->setupUi(this);

    QPushButton* ui_selectEasy = findChild<QPushButton*>("selectEasy");
    QPushButton* ui_selectMedium = findChild<QPushButton*>("selectMedium");
    QPushButton* ui_selectHard = findChild<QPushButton*>("selectHard");

    connect(ui_selectEasy, SIGNAL (released()), this, SLOT (on_select_easy()));
    connect(ui_selectMedium, SIGNAL (released()), this, SLOT (on_select_medium()));
    connect(ui_selectHard, SIGNAL (released()), this, SLOT (on_select_hard()));
}

GameConfig::~GameConfig()
{
    delete ui;
}

void GameConfig::on_select_easy()
{
return;
}
void GameConfig::on_select_medium()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();//this will disappear main window
}

void GameConfig::on_select_hard()
{
    QApplication::quit();
}*/
