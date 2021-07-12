//
//  main.cpp
//  22_Pure_Virtual_Function_and_Abstract_Class
//
//  Created by 세광 on 2021/07/12.
//

// 순수 가상 함수의 특징: 인스턴스를 만들 수 없음, 즉 순수 가상 함수를 하나라도 가지고 있는 class는 그 타입을 가진 객체를 만들 수 없음 (추상 class)
// 추상 class: 하나 이상의 순수 가상 함수를 포함하는 class

#include <iostream>

using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
    virtual double GetArea() = 0; // 순수 가상 함수의 표기
    virtual void Resize(double f) = 0;
};

class Circle : public Shape {
public:
    Circle(double r) : r(r) { }
    
    double GetArea() {
        return PI * r * r;
    }
    
    void Resize(double f) {
        r *= f;
    }
    
private:
    double r;
};

class Rectangle : public Shape {
public:
    Rectangle(double a, double b) : a(a), b(b) { }
    
    double GetArea() {
        return a * b;
    }
    
    void Resize(double f) {
        a *= f;
        b *= f;
    }
    
private:
    double a, b;
};

int main() {
    Shape *shapes[] = {
        new Circle(10),
        new Rectangle(20, 30)
    };
    
    for(Shape *s : shapes) {
        s->Resize(2);
    }
    for(Shape *s : shapes) {
        cout << s->GetArea() << endl;
    }
    for(Shape *s : shapes) {
        delete s;
    }
}
