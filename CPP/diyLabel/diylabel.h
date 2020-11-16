#ifndef DIYLABEL_H
#define DIYLABEL_H

#include<QLabel>
class DiyLabel:public QLabel
{
    Q_OBJECT
public:
    DiyLabel(QWidget * parent=nullptr);

protected:
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // DIYLABEL_H
