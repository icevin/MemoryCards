#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);


    QPushButton* ui_newGameButton = findChild<QPushButton*>("newGame");
    QPushButton* ui_settingsButton = findChild<QPushButton*>("settings");
    QPushButton* ui_exitButton = findChild<QPushButton*>("exit");

    connect(ui_newGameButton, SIGNAL (released()), this, SLOT (on_New_Game_clicked()));
    connect(ui_settingsButton, SIGNAL (released()), this, SLOT (on_Settings_clicked()));
    connect(ui_exitButton, SIGNAL (released()), this, SLOT (on_Exit_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_New_Game_clicked()
{
    return;
}
void MainWindow::on_Settings_clicked()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();//this will disappear main window
}

void MainWindow::on_Exit_clicked()
{
    QApplication::quit();
}
