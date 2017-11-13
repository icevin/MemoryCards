#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if (newGame(clicked())){
     QWidget *wdg = new QWidget;
     wdg->show();
    }
    return a.exec();
}
