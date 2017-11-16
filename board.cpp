#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent)
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

}
