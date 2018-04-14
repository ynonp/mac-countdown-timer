#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSystemTrayIcon;
class QTimer;
class ResizeEvent;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void restart();
    void tick();
    void updateDisplay();
    void promptForNewValue();
    void setFontSize(int value);
private:
    Ui::MainWindow *ui;
    int _secondsLeft = 300;
    int _startValue = 300;
    QTimer *_t;
};

#endif // MAINWINDOW_H
