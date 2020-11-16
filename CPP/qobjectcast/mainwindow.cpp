#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->leftButton,&QPushButton::clicked,this,&MainWindow::onButtonClicked);
    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::onButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton *button =  qobject_cast<QPushButton *>(sender());

    ui->textLabel->setText(button->text());

    if(ui->leftButton == button)
    {
        qDebug()<<"left Button clicked";
        ui->textLabel->setStyleSheet("background-color:yellow");
        button->setStyleSheet("background-color:yellow");

    }
    else
    {
        ui->textLabel->setStyleSheet("background-color:green");
        button->setStyleSheet("background-color:green");
    }

}

