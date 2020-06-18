/*
 * @Author : Akko
 * @Date : 2020-06-17 17:05:41
 * @LastEditTime : 2020-06-17 17:12:32
 * @LastEditors : Akko
 * @Description : 理解多重继承二义性产生的原因，熟悉解决二义性的方法
 * @FilePath : \object-oriented analysis and design\Lab3\Ambiguity_2.cpp
 * @Copyright © 2020 Akko All rights reserved.
*/
#include <iostream>
using namespace std;
class base
{
private:
    int a;

public:
    base(int x)
    {
        a = x;
        cout << "Constructing base a=" << a << endl;
    }
};
class base1 : virtual public base
{
private:
    int b;

public:
    base1(int x1, int x2) : base(x1)
    {
        b = x2;
        cout << "Constructing base1 b=" << b << endl;
    }
};
class base2 : virtual public base
{
private:
    int c;

public:
    base2(int x1, int x2) : base(x1)
    {
        c = x2;
        cout << "Constructing base2 c=" << c << endl;
    }
};
class derived : public base1, public base2
{
private:
    int d;

public:
    // derived(int x1, int x2, int x3, int x4) : base1(x1, x2), base2(x1, x3)
    derived(int x1,int x2,int x3,int x4):base(x1),base1(x1,x2),base2(x1,x3)
    {
        d = x4;
        cout << "Constructing derived d=" << d << endl;
    }
};
int main(void)
{
    derived obj(2, 3, 4, 5);
    return 0;
}
