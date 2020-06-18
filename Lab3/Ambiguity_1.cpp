/*
 * @Author : Akko
 * @Date : 2020-06-17 16:19:48
 * @LastEditTime : 2020-06-17 16:49:58
 * @LastEditors : Akko
 * @Description : 理解多重继承二义性产生的原因，熟悉解决二义性的方法
 * @FilePath : \object-oriented analysis and design\Lab3\Ambiguity.cpp
 * @Copyright © 2020 Akko All rights reserved.
*/
#include <iostream>
using namespace std;
class X
{
    int x;

public:
    X(int a = 0) { x = a; } //基类X的构造函数
    void set_x(int a) { x = a; }
    void show(void)
    {
        cout << "  x=" << x;
    }
};
class Y
{
    int y;

public:
    Y(int b = 0) { y = b; } //基类Y的构造函数
    void set_y(int b) { y = b; }
    void show(void)
    {
        cout << "  y=" << y;
    }
};
class Z : public X, public Y
//class Z:public X,private Y
{
    int z;

public:
    Z(int a = 0, int b = 0, int c = 0) : X(a), Y(b)
    {
        z = c;
    } //派生类Z的构造函数
    void set_xyz(int a, int b, int c)
    {
        set_x(a);
        set_y(b);
        z = c;
    }
    void show_z(void)
    {
        cout << "  z=" << z;
    }
    void print(void)
    {
        X::show(); //显示x的值
        Y::show(); //显示y的值
        show_z();  //显示z的值
    }
};
int main()
{
    Z obj1(3, 4, 5), obj2;
    obj2.set_xyz(10, 20, 30);
    obj1.print();
    cout << endl;
    obj2.print();
    cout << endl;
    return 0;
}