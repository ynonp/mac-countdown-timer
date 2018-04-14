#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _t = new QTimer();
    QObject::connect(_t, &QTimer::timeout, this, &MainWindow::tick);
    _t->setInterval(1000);
    _t->start();

    QObject::connect(ui->btnRestart, &QPushButton::clicked, this, &MainWindow::restart);
    QObject::connect(ui->btnSelectValue, &QPushButton::clicked, this, &MainWindow::promptForNewValue);

    setWindowTitle("");
    ui->fontsizeSlider->setValue(ui->label->font().pointSize());
    QObject::connect(ui->fontsizeSlider, &QSlider::valueChanged, this, &MainWindow::setFontSize);
}

void MainWindow::promptForNewValue()
{
    _startValue = QInputDialog::getInt(this, "Select New Timeout Value", "Seconds: ", _startValue, 0, 3540);
    restart();
}

void MainWindow::setFontSize(int value)
{
    QFont f = ui->label->font();
    f.setPointSize(value);
    ui->label->setFont(f);
    resize(minimumSize());
}

void MainWindow::restart()
{
    _secondsLeft = _startValue;
    updateDisplay();
    _t->stop();
    _t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    ui->label->setText(QString("%1:%2").arg(
                           QString::number(_secondsLeft / 60).rightJustified(2, '0'),
                           QString::number(_secondsLeft % 60).rightJustified(2, '0')
                           ));
}

void MainWindow::tick()
{
    if (_secondsLeft > 0) {
        _secondsLeft--;
    }
    updateDisplay();
}
