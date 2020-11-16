#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QEvent>
#include<QMouseEvent>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ui->label->installEventFilter(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

bool mainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->label)
    {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->buttons() ==Qt::RightButton)
            {
                 qDebug()<<"right button press  ";
                 event->accept();
            }
            else if (mouseEvent->buttons() ==Qt::LeftButton)
            {
                qDebug()<<"left button press  ";
                 // standard event processing
                return QObject::eventFilter(obj, event);
            }
        } else {
            return QObject::eventFilter(obj, event);
        }
    }
}

