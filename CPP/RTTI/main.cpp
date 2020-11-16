#include<QDebug>
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
    qDebug() << typeid(base).name();  // class Base
    qDebug() << typeid(derived).name();  // class Derived
    qDebug() << typeid(ptr).name();  // class Base *
    qDebug() << typeid(*ptr).name() ;  //class Derived
    qDebug() << typeid(ref).name() ;  //class Derived

}
