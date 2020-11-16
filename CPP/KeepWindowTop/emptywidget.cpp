#include "emptywidget.h"
#include "ui_emptywidget.h"

EmptyWidget::EmptyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmptyWidget)
{
    ui->setupUi(this);
}

EmptyWidget::~EmptyWidget()
{
    delete ui;
}
