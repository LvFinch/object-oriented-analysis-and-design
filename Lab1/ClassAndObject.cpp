/*
 * @Author : Akko
 * @Date : 2020-06-14 12:49:21
 * @LastEditTime : 2020-06-14 15:32:38
 * @LastEditors : Akko
 * @Description : 找出一个整型数组中的元素的最大值，并对数组进行排序。
 * @FilePath : \object-oriented analysis and design\Lab1\ClassAndObject.cpp
 * @Copyright  ? 2020 Akko All rights reserved.
*/
#include <iostream>
using namespace std;

#define MAXSIZE 50
/*
class -- Array
(1)数据成员包含：
    两个数组，一个用于保存原始数据，另一个则用于保存有序的数据（递增或递减自定）;
    一个用于存放最大值的数据成员;一个用于存放最大值所在数组中的位置的数据成员;
(2)成员函数：
    一个用于求最大值和及其在数组中的位置;
    另一个用于排序，排序方法不定（可以用数据结构里讲的五大类排序方法的一种）;
    最后一个用于结果的输出;
(3)定义构造函数完成初始化工作，允许用户定义对象时给对象赋初值，定义析构函数;
(4)定义对象，通过对象完成所有操作.
*/
class Array
{
private:
    int OriginalArray[MAXSIZE]; //原始数组:保存原始数据
    int OrderedArray[MAXSIZE];  //有序数组:保存有序数据
    int ArrayMax;               //数组最大值
    int ArrayMaxLocation;       //最大值的位置
    int ArrayLength;            //数组的长度
public:
    Array(){};             //构造函数:无参
    Array(int a[]);        //构造函数:自定义
    int *ArrayIn();        //原始数据输入
    void PickMax(int a[]); //求最大值及其所在位置
    void Rank(int a[]);    //冒泡法排序
    void ArrayOut();       //结果输出
    ~Array() {}            //析构函数
};
/* class -- Array*/

/*
Type:None
Name:Array()
Parameter:int
Summary:用构造函数赋值
Return:None
*/
Array::Array(int a[])
{
    int i;
    cout << "——由用户定义对象时赋值——" << endl;
    for (i = 0; i < MAXSIZE; i++)
    {
        OriginalArray[i] = a[i];
        if (a[i] == -999)
            break; //数组以-999结束
    }
    ArrayLength = i;
}
/*
Type:int
Name:ArrayIn()
Parameter:None
Summary:用成员函数赋值
Return:OriginalArray
*/
int *Array::ArrayIn()
{
    cout << "——由成员函数动态赋值——" << endl;
    int a, i;
    cout << "请输入一组数据，由-999结束：" << endl;
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
Summary:选出最大值
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
Summary:排序
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
Summary:输出结果
Return:None
*/
void Array::ArrayOut()
{
    int i;
    //输出原始数据
    cout << "原始数据为：" << endl;
    for (i = 0; i < ArrayLength; i++)
        cout << OriginalArray[i] << " ";
    cout << endl;
    //输出最大值及其位置
    cout << "最大值为：" << ArrayMax << "; 位置为:" << ArrayMaxLocation + 1 << endl;
    //输出递增序列
    cout << "由小到大排序为：" << endl;
    for (i = 0; i < ArrayLength; i++)
        cout << OrderedArray[i] << " ";
    cout << endl
         << endl;
}

int main()
{
    //定义对象时赋初值
    int a[] = {11, 12, 13, 1, 2, 3, -999};
    Array A(a);
    A.PickMax(a);
    A.Rank(a);
    A.ArrayOut();

    //调用成员函数赋值
    Array B;
    int *b = B.ArrayIn();
    B.PickMax(b);
    B.Rank(b);
    B.ArrayOut();
    return 0;
}