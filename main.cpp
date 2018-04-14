#include "mainwindow.h"
#include <QApplication>

#ifdef __APPLE__
#include "OSXHideTitleBar.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();    
    OSXHideTitleBar::HideTitleBar(w.winId());

    return a.exec();
}
