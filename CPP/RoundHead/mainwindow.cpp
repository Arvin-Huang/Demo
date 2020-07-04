#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QImage>
#include<QPainter>
#include<QString>
#include<QDebug>
#include<QColor>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowOpacity(1);
//    this->setAttribute(Qt::WA_TranslucentBackground);

    headImag = new QImage;
    headImag->load(QString::fromUtf8(":/img/head.png"));



        QLabel *label = new QLabel();
        int size = 200;
        QString qss = QString(
                    "min-width:  %1px;"
                    "max-width:  %2px;"
                    "min-height: %3px;"
                    "max-height: %4px;"
                    "border-radius: %5px;"
                    "border-width: 0 0 0 0;"
                    "border-image: url(%6) 0 0 0 0 stretch strectch;"
                    ).arg(size).arg(size)
                  .arg(size).arg(size).arg(size/2).arg(":/img/head.png");
        qDebug()<<qss;
        label->setStyleSheet(qss);
        label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    /*
     * 设置窗体透明时
     * this->setWindowFlags(Qt::FramelessWindowHint);
     * this->setWindowOpacity(1);
     * this->setAttribute(Qt::WA_TranslucentBackground);
     * */
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.fillRect(headImag->rect(), QBrush(QColor::fromRgb(170, 170, 255), Qt::SolidPattern));
//    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
//    painter.drawEllipse(headImag->rect());
//    painter.drawPixmap(0,0,QPixmap::fromImage(*headImag));


    /**
     *窗体不透明时
     */
    QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing);
     //设置头像底色
     painter.fillRect(headImag->rect(), QBrush(QColor::fromRgb(170, 170, 255), Qt::SolidPattern));
     painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
     //设置透明圆形
     painter.setPen(Qt::NoPen);
     painter.setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
     painter.drawEllipse(headImag->rect());
     painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
     //绘制头像
     painter.drawPixmap(0,0,QPixmap::fromImage(*headImag));




}

