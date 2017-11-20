#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QMainWindow>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE

class MainWindow;

class ConfigW : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigW(MainWindow* parent);
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectEast;
    QPushButton *selectMedium;
    QPushButton *selectHard;
    MainWindow *parent;
signals:

public slots:
    void on_select_easy(); //5 minutes, 20 cards
    void on_select_medium(); //2 minutes, 20 cards
    void on_select_hard(); //2 minutes,
};

#endif // CONFIG_H
