#ifndef NEWGAME_H
#define NEWGAME_H
#include <QWidget>
#include <QObject>


class GameConfig : public QWidget
{
    Q_OBJECT

public:
    explicit GameConfig(QWidget *parent = 0);
    ~GameConfig();

private:
    GameConfig *ui;
public slots:
    void on_select_easy();
    void on_select_medium();
    void on_select_hard();
};

#endif // NEWGAME_H
