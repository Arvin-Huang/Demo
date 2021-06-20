#include "diylabel.h"
#include<QDebug>


DiyLabel::DiyLabel(QWidget * parent)
    :QLabel(parent)
{

}

void DiyLabel::enterEvent(QEvent *event)
{
    qDebug()<<"mouse enter ";
    QLabel::enterEvent(event);
}

void DiyLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"mouse press ";
    QLabel::mousePressEvent(ev);

}

