#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMainWindow>
#include <string>
#include "config.h"

namespace Ui {
class MainWindow;
}

class ConfigW;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::string options;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConfigW* c;
public slots:
    void on_New_Game_clicked();
    void on_Rules_clicked();
    void on_Exit_clicked();
};


#endif
