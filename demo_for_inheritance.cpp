#include<iostream>
using namespace std;
class Base{
public:
    int a;
protected:
    int b; 
private:
    int c;
public:
    Base();
    ~Base();
};
Base::Base() {
}
Base::~Base() {
}

class Derived1 : public Base { // public继承
public:
    void xfunc1() {
        x = a; // 基类中的公有成员能被“派生类”访问。
    }
    void xfunc2() {
        x = b; // 基类中的保护成员能被“派生类”访问。
    }
    void xfunc3() {
        //x = c; // 私有成员不能被“派生类”访问
    }
private:
    int x;
public:
    Derived1();
    ~Derived1();
};

Derived1::Derived1() {
}
Derived1::~Derived1() {
}

class Derived2 : protected Base { // protected继承
private:
    int y;
    void yfunc1() {
        y = a; // 基类中的公有成员能被“派生类”访问。
    }
    void yfunc2() {
        y = b; // 基类中的保护成员能被“派生类”访问。
    }
    void yfunc3() {
        //y = c; // 私有成员不能被“派生类”访问
    }
public:
    Derived2();
    ~Derived2();
};

Derived2::Derived2() {
}
Derived2::~Derived2() {
}

class Derived3 : private Base { // private继承
private:
    int z;
    void zfunc1() {
        z = a; // 基类中的公有成员能被“派生类”访问。
    }
    void zfunc2() {
        z = b; // 基类中的保护成员能被“派生类”访问。
    }
    void zfunc3() {
        //z = c; // 私有成员不能被“派生类”访问
    }
public:
    Derived3();
    ~Derived3();
};

Derived3::Derived3() {
}
Derived3::~Derived3() {
}

int main() {
    Base parent1;
    parent1.a = 1;
    //parent1.b = 2; // 对象不能访问类中protected 属性的成员。
    //parent1.c = 3; // 对象不能访问类中private 属性的成员。
    Derived1 child1;
    child1.a = 1;
    //child1.b = 2; // public继承下的 派生类对象 不能访问基类 protected 属性的成员
    //child1.c = 3; // public继承下的 派生类对象 不能访问基类 private 属性的成员
    Derived2 child2;
    //child2.a = 1; // protected继承下的 派生类对象 不能访问基类 public 属性的成员
    //child2.b = 2; // protected继承下的 派生类对象 不能访问基类 protected 属性的成员
    //child2.c = 3; // protected继承下的 派生类对象 不能访问基类 private 属性的成员
    Derived3 child3;
    //child3.a = 1; // private继承下的 派生类对象 不能访问基类 public 属性的成员
    //child3.b = 2; // private继承下的 派生类对象 不能访问基类 protected 属性的成员
    //child3.c = 3; // private继承下的 派生类对象 不能访问基类 private 属性的成员
    return 0;
}