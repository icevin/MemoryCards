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

QT_BEGIN_NAMESPACE

class ConfigW : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigW(QWidget *parent = nullptr);
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectEast;
    QPushButton *selectMedium;
    QPushButton *selectHard;
signals:

public slots:
    void on_select_easy();
    void on_select_medium();
    void on_select_hard();
};

#endif // CONFIG_H
