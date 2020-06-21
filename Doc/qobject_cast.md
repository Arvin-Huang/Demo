## Qt 在槽函数中获取信号发送对象

Qt中提供了一个函数 qobject_cast(QObject *object),可以通过这个函数判断信号发出对象

>Qt 帮助文档的解释：
Returns the given object cast to type T if the object is of type T (or of a subclass); otherwise returns nullptr. If object is nullptr then it will also return nullptr.
The class T must inherit (directly or indirectly) QObject and be declared with the Q_OBJECT macro.
A class is considered to inherit itself.
The qobject_cast() function behaves similarly to the standard C++ dynamic_cast(), with the advantages that it doesn't require RTTI support and it works across dynamic library boundaries.


+ 简单来说 就是使用这个函数会得到你转型的的一个实例，但是这个类必须继承自QObject 或者其子类并且声明Q_OBJECT 这个宏 
+ QT 帮助文档中一个Example
  ```
  QObject *obj = new QTimer; 
  QTimer *timer = qobject_cast<QTimer *>(obj);
  ```

这里顺便记录一下RTTI 与RAII，RAII 通常应用于对象资源管理，RTTI 可以动态判断对象类型，但使用RTTI增加程序运行时间，这里简单记录区分一下 。

1. RTTI : Run-time  type information
   
    ```
    #include <iostream>
    #include <typeinfo>

    class Base {
    public:
        virtual ~Base() = default;
    };

    class Derived : public Base {};

    int main() {
        Base base;
        Derived derived;
        Base* ptr = &derived;
        Base& ref = derived;
        std::cout << typeid(base).name()<< std::endl;  // class Base 
        std::cout << typeid(derived).name()<< std::endl;  // class Derived
        std::cout << typeid(ptr).name()<< std::endl;  // class Base *
        std::cout << typeid(*ptr).name() << std::endl;  //class Derived           
        std::cout << typeid(ref).name() << std::endl;  //class Derived

    }
    ```

2. RAII :  Resource Acquisition Is Initialization

    ```
    代码来源 https://en.cppreference.com/w/cpp/language/raii
    std::mutex m;
    
    void bad() 
    {
        m.lock();                    // acquire the mutex
        f();                         // if f() throws an exception, the mutex is never released
        if(!everything_ok()) return; // early return, the mutex is never released
        m.unlock();                  // if bad() reaches this statement, the mutex is released
    }
    
    void good()
    {
        std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
        f();                               // if f() throws an exception, the mutex is released
        if(!everything_ok()) return;       // early return, the mutex is released
    }
    ```

下面是QT通过qobject_cast获取信号发送对象的一个Demo,通过Qt Desinger 绘制两个按钮和一个文本框，将两个按钮的点击事件连接到同一个槽函数，在槽函数里面判断信号的发送者并作出不同的响应
主要的代码如下：
```
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onButtonClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


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


```
完整的代码已上传[Github](https://github.com/iamarvinh/Demo/tree/master/qobjectcast)


