#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include <vector>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    explicit Board(int cards, QWidget *parent = nullptr);
    vector<vector<QPushButton>> board;
    int cardCount;

signals:

public slots:
    void cardSelect(int, int);
    void endGame();
    void restartGame();
private:
    void updateLayout();
};

#endif // BOARD_H
