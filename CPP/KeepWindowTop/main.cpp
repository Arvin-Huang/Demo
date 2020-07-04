#include "mainwindow.h"
#include "emptywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();

    EmptyWidget * w1 = new EmptyWidget();

    w1->show();


    return a.exec();
}
