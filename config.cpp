#include "config.h"

ConfigW::ConfigW(QWidget *parent) : QWidget(parent)
{
    this->resize(469, 205);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    label = new QLabel("Select Difficulty");
    label->setObjectName(QStringLiteral("label"));
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setScaledContents(false);
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    selectEast = new QPushButton(this);
    selectEast->setObjectName(QStringLiteral("selectEast"));

    horizontalLayout->addWidget(selectEast);

    selectMedium = new QPushButton(this);
    selectMedium->setObjectName(QStringLiteral("selectMedium"));

    horizontalLayout->addWidget(selectMedium);

    selectHard = new QPushButton(this);
    selectHard->setObjectName(QStringLiteral("selectHard"));

    horizontalLayout->addWidget(selectHard);


    verticalLayout->addLayout(horizontalLayout);


    this->setWindowTitle(QApplication::translate("Select Difficulty", "Select Difficulty", Q_NULLPTR));
           label->setText(QApplication::translate("this", "SELECT DIFFICULTY", Q_NULLPTR));
           selectEast->setText(QApplication::translate("this", "Easy", Q_NULLPTR));
           selectMedium->setText(QApplication::translate("this", "Medium", Q_NULLPTR));
           selectHard->setText(QApplication::translate("this", "Hard", Q_NULLPTR));

            QMetaObject::connectSlotsByName(this);

            QPushButton* ui_selectEasy = findChild<QPushButton*>("selectEasy");
            QPushButton* ui_selectMedium = findChild<QPushButton*>("selectMedium");
            QPushButton* ui_selectHard = findChild<QPushButton*>("selectHard");

            connect(ui_selectEasy, SIGNAL (released()), this, SLOT (on_select_easy()));
            connect(ui_selectMedium, SIGNAL (released()), this, SLOT (on_select_medium()));
            connect(ui_selectHard, SIGNAL (released()), this, SLOT (on_select_hard()));
}


void ConfigW::on_select_easy()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();
}
void ConfigW::on_select_medium()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();//this will disappear main window
}

void ConfigW::on_select_hard()
{
    QWidget *wdg = new QWidget;
    wdg->show();
    hide();
}

/********************************************************************************
** this generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OUT_H
#define OUT_H

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


// namespace Ui

QT_END_NAMESPACE

#endif // OUT_H
