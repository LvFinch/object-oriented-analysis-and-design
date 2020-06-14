/*
 * @Author : Akko
 * @Date : 2020-06-14 13:09:27
 * @LastEditTime : 2020-06-14 15:01:46
 * @LastEditors : Akko
 * @Description : �ͻ����ݹ����ͻ���Ϣ���룬�����
 * @FilePath : \object-oriented analysis and design\Lab2\Inheritance.cpp
 * @Copyright ? 2020 Akko All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

#define MAXSIZE 50
/*
class -- Customer
===============================
��Ա:
    �ͻ����
    �ͻ�����
    ��ע
��Ա����:
    read();
    show();
===============================
*/
class Customer
{
public:
    char Cust_ID[10];   //�ͻ����
    char Cust_Name[10]; //�ͻ�����
    char Desc[MAXSIZE]; //��ע

public:
    Customer();
    ~Customer();
    void read(); //��ֵ
    void show(); //���
};
Customer::Customer() {}

Customer::~Customer() {}
/*
===============================
class -- Corp_Cust
��Ա:
    �ۿۼ�
    ���õȼ�
===============================
*/
class Corp_Cust : public Customer
{
public:
    char Off_Price[5];  //�ۿۼ�
    char Trust_Leve[3]; //���õȼ�

public:
    Corp_Cust();
    ~Corp_Cust();
    void read(); //��ֵ
    void show(); //���
};
Corp_Cust::Corp_Cust() {}

Corp_Cust::~Corp_Cust() {}

/*
-------------------------------
Type:void
Name:read()
Parameter:None
Summary:��ֵ
Return:None
-------------------------------
*/
void Corp_Cust::read()
{
    cout << "========��Ϣ����========" << endl;
    cout << "������ͻ���� : " << endl;
    cin >> Cust_ID;
    cout << "������ͻ����� : " << endl;
    cin >> Cust_Name;
    cout << "������ͻ���ע : " << endl;
    cin >> Desc;
    cout << "�������ۿۼ� : " << endl;
    cin >> Off_Price;
    cout << "���������õȼ� : " << endl;
    cin >> Trust_Leve;
    cout << "========�������========" << endl
         << endl;
}

/*
-------------------------------
Type:void
Name:show()
Parameter:None
Summary:���
Return:None
-------------------------------
*/
void Corp_Cust::show()
{
    cout << "--------��Ϣ���--------" << endl;
    cout << "�ͻ���� : " << Cust_ID << endl;
    cout << "�ͻ����� : " << Cust_Name << endl;
    cout << "�ͻ���ע : " << Desc << endl;
    cout << "�ۿۼ� : " << Off_Price << endl;
    cout << "���õȼ� : " << Trust_Leve << endl;
    cout << "--------�������--------" << endl
         << endl;
}

/*
===============================
class -- Vip_Cust
��Ա:
    �绰����
    VIP�ȼ�
===============================
*/
class Vip_cust : public Customer
{
public:
    char Phone[11];   //�绰����
    char Vip_Leve[3]; //VIP�ȼ�

public:
    Vip_cust();
    ~Vip_cust();
    void read(); //��ֵ
    void show(); //���
};
Vip_cust::Vip_cust() {}

Vip_cust::~Vip_cust() {}

/*
-------------------------------
Type:void
Name:read()
Parameter:None
Summary:���
Return:None
-------------------------------
*/
void Vip_cust::read()
{
    cout << "========��Ϣ����========" << endl;
    cout << "������绰���룺" << endl;
    cin >> Phone;
    cout << "������VIP�ȼ���" << endl;
    cin >> Vip_Leve;
    cout << "========�������========" << endl
         << endl;
};

/*
-------------------------------
Type:void
Name:show()
Parameter:None
Summary:���
Return:None
-------------------------------
*/
void Vip_cust::show()
{
    cout << "--------��Ϣ���--------" << endl;
    cout << "�绰���룺" << Phone << endl;
    cout << "VIP�ȼ���" << Vip_Leve << endl;
    cout << "--------�������--------" << endl
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