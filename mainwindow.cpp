#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "rules.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    options = "0";

    QPushButton* ui_newGameButton = findChild<QPushButton*>("newGame");
    QPushButton* ui_settingsButton = findChild<QPushButton*>("rules");
    QPushButton* ui_exitButton = findChild<QPushButton*>("exit");

    connect(ui_newGameButton, SIGNAL (released()), this, SLOT (on_New_Game_clicked()));
    connect(ui_settingsButton, SIGNAL (released()), this, SLOT (on_Rules_clicked()));
    connect(ui_exitButton, SIGNAL (released()), this, SLOT (on_Exit_clicked()));
    c = new ConfigW(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_New_Game_clicked()
{
    c->show();
    hide();//this will disappear main window
}
void MainWindow::on_Rules_clicked()
{
    rules* r = new rules(this,1);
    r->show();
    hide();
}

void MainWindow::on_Exit_clicked()
{
    QApplication::quit();
}
