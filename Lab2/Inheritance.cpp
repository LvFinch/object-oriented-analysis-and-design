/*
 * @Author : Akko
 * @Date : 2020-06-14 13:09:27
 * @LastEditTime : 2020-06-14 17:17:36
 * @LastEditors : Akko
 * @Description : 客户数据管理：客户信息输入，输出。
 * @FilePath : \object-oriented analysis and design\Lab2\Inheritance.cpp
 * @Copyright ? 2020 Akko All rights reserved.
*/
#include <iostream>

using namespace std;

#define MAXSIZE 50
/*
class -- Customer
===============================
成员:
    客户编号
    客户姓名
    备注
成员函数:
    read();
    show();
===============================
*/
class Customer
{
public:
    string Cust_ID;   //客户编号
    string Cust_Name; //客户姓名
    string Desc; //备注

public:
    Customer();
    ~Customer();
    void read(); //赋值
    void show(); //输出
};
Customer::Customer() {}

Customer::~Customer() {}
/*
===============================
class -- Corp_Cust
成员:
    折扣价
    信用等级
===============================
*/
class Corp_Cust : public Customer
{
public:
    string Off_Price;  //折扣价
    string Trust_Leve; //信用等级

public:
    Corp_Cust();
    ~Corp_Cust();
    void read(); //赋值
    void show(); //输出
};
Corp_Cust::Corp_Cust() {}

Corp_Cust::~Corp_Cust() {}

/*
-------------------------------
Type:void
Name:read()
Parameter:None
Summary:赋值
Return:None
-------------------------------
*/
void Corp_Cust::read()
{
    cout << "========信息输入========" << endl;
    cout << "请输入客户编号 : " << endl;
    cin >> Cust_ID;
    cout << "请输入客户姓名 : " << endl;
    cin >> Cust_Name;
    cout << "请输入客户备注 : " << endl;
    cin >> Desc;
    cout << "请输入折扣价 : " << endl;
    cin >> Off_Price;
    cout << "请输入信用等级 : " << endl;
    cin >> Trust_Leve;
    cout << "========输入结束========" << endl
         << endl;
}

/*
-------------------------------
Type:void
Name:show()
Parameter:None
Summary:输出
Return:None
-------------------------------
*/
void Corp_Cust::show()
{
    cout << "--------信息输出--------" << endl;
    cout << "客户编号 : " << Cust_ID << endl;
    cout << "客户姓名 : " << Cust_Name << endl;
    cout << "客户备注 : " << Desc << endl;
    cout << "折扣价 : " << Off_Price << endl;
    cout << "信用等级 : " << Trust_Leve << endl;
    cout << "--------输出结束--------" << endl
         << endl;
}

/*
===============================
class -- Vip_Cust
成员:
    电话号码
    VIP等级
===============================
*/
class Vip_cust : public Customer
{
public:
    string Phone;   //电话号码
    string Vip_Leve; //VIP等级

public:
    Vip_cust();
    ~Vip_cust();
    void read(); //赋值
    void show(); //输出
};
Vip_cust::Vip_cust() {}

Vip_cust::~Vip_cust() {}

/*
-------------------------------
Type:void
Name:read()
Parameter:None
Summary:输出
Return:None
-------------------------------
*/
void Vip_cust::read()
{
    cout << "========信息输入========" << endl;
    cout << "请输入电话号码：" << endl;
    cin >> Phone;
    cout << "请输入VIP等级：" << endl;
    cin >> Vip_Leve;
    cout << "========输入结束========" << endl
         << endl;
};

/*
-------------------------------
Type:void
Name:show()
Parameter:None
Summary:输出
Return:None
-------------------------------
*/
void Vip_cust::show()
{
    cout << "--------信息输出--------" << endl;
    cout << "电话号码：" << Phone << endl;
    cout << "VIP等级：" << Vip_Leve << endl;
    cout << "--------输出结束--------" << endl
         << endl;
};

int main()
{
    Corp_Cust A;
    Vip_cust B;
    A.read();
    A.show();
    B.read();
    B.show();
    return 0;
}