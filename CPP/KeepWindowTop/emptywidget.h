#ifndef EMPTYWIDGET_H
#define EMPTYWIDGET_H

#include <QWidget>

namespace Ui {
class EmptyWidget;
}

class EmptyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmptyWidget(QWidget *parent = nullptr);
    ~EmptyWidget();

private:
    Ui::EmptyWidget *ui;
};

#endif // EMPTYWIDGET_H
