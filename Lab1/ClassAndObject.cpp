/*
 * @Author : Akko
 * @Date : 2020-06-14 12:49:21
 * @LastEditTime : 2020-06-14 13:11:07
 * @LastEditors : Akko
 * @Description : �ҳ�һ�����������е�Ԫ�ص����ֵ�����������������
 * @FilePath : \object-oriented analysis and design\Lab1\ClassAndObject.cpp
 * @Copyright  ? 2020 Akko All rights reserved.
*/
#include <iostream>
using namespace std;

#define MAXSIZE 50
/*
class -- Array
(1)���ݳ�Ա������
    �������飬һ�����ڱ���ԭʼ���ݣ���һ�������ڱ�����������ݣ�������ݼ��Զ���;
    һ�����ڴ�����ֵ�����ݳ�Ա;һ�����ڴ�����ֵ���������е�λ�õ����ݳ�Ա;
(2)��Ա������
    һ�����������ֵ�ͼ����������е�λ��;
    ��һ�������������򷽷����������������ݽṹ�ｲ����������򷽷���һ�֣�;
    ���һ�����ڽ�������;
(3)���幹�캯����ɳ�ʼ�������������û��������ʱ�����󸳳�ֵ��������������;
(4)�������ͨ������������в���.
*/
class Array
{
private:
    int OriginalArray[MAXSIZE]; //ԭʼ����:����ԭʼ����
    int OrderedArray[MAXSIZE];  //��������:������������
    int ArrayMax;               //�������ֵ
    int ArrayMaxLocation;       //���ֵ��λ��
    int ArrayLength;            //����ĳ���
public:
    Array(){};             //���캯��:�޲�
    Array(int a[]);        //���캯��:�Զ���
    int *ArrayIn();        //ԭʼ��������
    void PickMax(int a[]); //�����ֵ��������λ��
    void Rank(int a[]);    //ð�ݷ�����
    void ArrayOut();       //������
    ~Array() {}            //��������
};
/* class -- Array*/

/*
Type:None
Name:Array()
Parameter:int
Summary:�ù��캯����ֵ
Return:None
*/
Array::Array(int a[])
{
    int i;
    cout << "�������û��������ʱ��ֵ����" << endl;
    for (i = 0; i < MAXSIZE; i++)
    {
        OriginalArray[i] = a[i];
        if (a[i] == -999)
            break; //������-999����
    }
    ArrayLength = i;
}
/*
Type:int
Name:ArrayIn()
Parameter:None
Summary:�ó�Ա������ֵ
Return:OriginalArray
*/
int *Array::ArrayIn()
{
    cout << "�����ɳ�Ա������̬��ֵ����" << endl;
    int a, i;
    cout << "������һ�����ݣ���-999������" << endl;
    for (i = 0; i <= 50; i++)
    {
        cin >> a;
        if (a == -999)
            break;
        else
            OriginalArray[i] = a;
    }
    ArrayLength = i;
    return OriginalArray;
}
/*
Type:void
Name:PickMax()
Parameter:int
Summary:ѡ�����ֵ
Return:None
*/
void Array::PickMax(int OriginalArray[])
{

    ArrayMaxLocation = 0;
    ArrayMax = OriginalArray[0];
    for (int i = 1; i < ArrayLength; i++)
    {
        if (OriginalArray[i] > ArrayMax)
        {
            ArrayMaxLocation = i;
            ArrayMax = OriginalArray[i];
        }
    }
}
/*
Type:void
Name:Rank()
Parameter:int
Summary:����
Return:None
*/
void Array::Rank(int OriginalArray[])
{
    int i, j, k;
    for (i = 0; i < ArrayLength; i++)
    {
        OrderedArray[i] = OriginalArray[i];
    }
    for (i = 0; i < ArrayLength; i++)
    {
        for (j = 0; j < ArrayLength - i - 1; j++)
            if (OrderedArray[j] > OrderedArray[j + 1])
            {
                k = OrderedArray[j + 1];
                OrderedArray[j + 1] = OrderedArray[j];
                OrderedArray[j] = k;
            }
    }
}
/*
Type:void
Name:ArrayOut
Parameter:None
Summary:������
Return:None
*/
void Array::ArrayOut()
{
    int i;
    //���ԭʼ����
    cout << "ԭʼ����Ϊ��" << endl;
    for (i = 0; i < ArrayLength; i++)
        cout << OriginalArray[i] << " ";
    cout << endl;
    //������ֵ����λ��
    cout << "���ֵΪ��" << ArrayMax << "; λ��Ϊ:" << ArrayMaxLocation + 1 << endl;
    //�����������
    cout << "��С��������Ϊ��" << endl;
    for (i = 0; i < ArrayLength; i++)
        cout << OrderedArray[i] << " ";
    cout << endl
         << endl;
}

int main()
{
    //�������ʱ����ֵ
    int a[] = {11, 12, 13, 1, 2, 3, -999};
    Array A(a);
    A.PickMax(a);
    A.Rank(a);
    A.ArrayOut();

    //���ó�Ա������ֵ
    Array B;
    int *b = B.ArrayIn();
    B.PickMax(b);
    B.Rank(b);
    B.ArrayOut();
    return 0;
}
