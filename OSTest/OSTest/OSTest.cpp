// OSTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <locale.h>
#include "func_declare.h"
using namespace std;

class A
{
private:
    int value;
public:
    A(int n){value = n;}
    A(A &other){value = other.value;}

    void print(){cout<<value<<endl;}
};

//int Partition(int data[], int length, int start, int end)
//{
//    if (data == NULL || length <= 0 || start < 0 || end >= length)
//        throw new std::exception("Invalid Parameters");
//    int index = 5;
//    Sw
//}

void swap(int *data, int i, int j)
{
    data[i] = data[i] + data[j];
    data[j] = data[i] - data[j];
    data[i] = data[i] - data[j];
}

int partition(int *data, int length, int start, int end)
{
    int index = 3;
    swap(data, index, end);
    int small = start - 1;
    for (int index=start; index<end; index++)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
            {
                swap(data, small, index);
            }
        }
    }

    ++small;
    swap(data, small, end);
    return small;
}


void main()
{
	//cout<<sizeof(_TCHAR)<<endl;

    //int data[8] = {10, 17, 20, 31, 6, 9, 18, 67};
    //int data[8] = {10, 17, 20, 31, 32, 98, 54, 67};
    //partition(data, 8, 0, 7);

    //comparePerformancezWithBit();

    //printToMaxOfDigits(3);
    //char p[4] = {0};
    //memcpy_s(p, _TRUNCATE, "abc", 4);

    //permutation(p);

    
    setlocale(LC_CTYPE, "");
    printfVariousData(L"sdccds%%, string=%s, int=%d, char=%c\n", L"中国人民共和国", 211, L'k');
    printfVariousData(L"sdccds%%, string=%s, int=%d, char=%c\n", L"hello world", 211, L'k');
    //printfVariousData(L"sdccds%%, string=%s, int=%d, char=%c\n", L"你好", 211, L'k');
}

