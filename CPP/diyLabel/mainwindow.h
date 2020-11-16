#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();
protected:
     bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::mainWindow *ui;
};
#endif // MAINWINDOW_H
