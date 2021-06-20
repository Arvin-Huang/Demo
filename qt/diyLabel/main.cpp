#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.setWindowTitle("平凡键客");
    w.show();
    return a.exec();
}
