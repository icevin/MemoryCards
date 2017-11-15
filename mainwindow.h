#include <QMainWindow>

namespace Ui {
class MainWindow;
class GameConfig;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void on_New_Game_clicked();
    void on_Settings_clicked();
    void on_Exit_clicked();
};

