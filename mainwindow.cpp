#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_New_Game_clicked()
{
    if (newGame(clicked())){
     QWidget *wdg = new QWidget;
     wdg->show();
    }
    hide();//this will disappear main window
}
void MainWindow::on_Settings_clicked()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();//this will disappear main window
}
void MainWindow::on_Exit_clicked()
{
return;
}
