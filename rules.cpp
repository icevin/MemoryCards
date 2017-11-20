#include "rules.h"
#include <string>


rules::rules(MainWindow* p, int d)
{
    ab=d;
    parent = p;
    QFont a;
    a.setBold(true);
    a.setPointSize(30);
    a.setUnderline(true);
    a.setWeight(75);

    QFont b;
    b.setWeight(50);
    b.setPointSize(18);

    l = new QVBoxLayout(this);
    title = new QLabel("Rules: ");
    title->setFont(a);

    std::string ruleText = "The object of the game is to match all of the cards. Each card has a number. "
            "Click on a card to select it, and again to deselect it. Upon selecting two cards, both will be flipped over."
            " If they are a match, they will stay flipped. If they are not, they will be turned "
            "face down again. Memorize the positions of each number to match all of the cards "
            "before time runs out. Points are awarded for matching cards, having extra time left over, "
            "and winning in the fewest moves.";

    ruleL = new QLabel();
    ruleL->setWordWrap(true);
    ruleL->setFont(b);
    ruleL->setText(QString::fromStdString(ruleText));
    ruleL->setContentsMargins(22,22,22,22);

    back = new QPushButton("Back");

    QFont c;
    c.setWeight(50);
    c.setBold(false);
    c.setPointSize(18);
    back->setFont(c);

    l->addWidget(title);
    l->addWidget(ruleL);
    l->addWidget(back);


    this->setWindowTitle(QStringLiteral("Rules"));
    connect(back, SIGNAL(released()),this,SLOT(on_back()));
    this->setMaximumHeight(550);
    this->setMaximumWidth(550);
}

void rules::on_back() {
    if(ab) {
        parent->show();
    }
    this->close();
}
