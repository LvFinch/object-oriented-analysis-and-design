/*
 * @Author : Akko
 * @Date : 2020-06-14 13:09:27
 * @LastEditTime : 2020-06-14 14:13:41
 * @LastEditors : Akko
 * @Description : 客户数据管理：客户信息输入，输出。
 * @FilePath : \object-oriented analysis and design\Lab2\Inheritance.cpp
 * @Copyright © 2020 Akko All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;
/*
class -- Customer
成员:
    客户编号
    客户姓名
    备注
成员函数:
    read();
    show();
*/
class Customer
{
private:
    string Cust_ID;   //客户编号
    string Cust_Name; //客户姓名
    string Desc;      //备注

public:
    Customer();
    ~Customer();
    void read(); //赋值
    void show(); //输出
};
//class -- Customer
Customer::Customer() {}

Customer::~Customer() {}
/* class -- Customer */
/*
class -- Corp_Cust
成员:
    折扣价
    信用等级
*/
class Corp_Cust : public Customer
{
private:
    string Off_Price;   //折扣价
    string Trust_Level; //信用等级

public:
    Corp_Cust();
    ~Corp_Cust();
};
//class -- Corp_Cust
Corp_Cust::Corp_Cust() {}

Corp_Cust::~Corp_Cust() {}
/*
-------------------------------
Type:None
Name:read()
Parameter:None
Summary:赋值
Return:None
-------------------------------
*/
Corp_Cust::read()
{
    cout << "请输入客户编号 : " << endl;
    cin >> Cust_ID;
    cout << "请输入客户姓名 : " << endl;
    cin >> Cust_Name;
    cout << "请输入客户备注 : " << endl;
    cin >> Desc;
    cout << "请输入折扣价 : " << endl;
    cin >> Off_Price;
    cout << "请输入信用等级 : " << endl;
    cin >> Trust_Level;
}
/*
-------------------------------
Type:None
Name:show()
Parameter:None
Summary:输出
Return:None
-------------------------------
*/
/*
class -- Vip_Cust
成员:
    电话号码
    VIP等级
*/
class Vip_cust : public Customer
{
private:
    string Phone;   //电话号码
    string VipLeve; //VIP等级

public:
    Vip_cust();
    ~Vip_cust();
};
//class -- Vip_Cust
Vip_cust::Vip_cust() {}

Vip_cust::~Vip_cust() {}
