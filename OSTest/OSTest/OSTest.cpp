// OSTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
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
	cout<<sizeof(_TCHAR)<<endl;

    //int data[8] = {10, 17, 20, 31, 6, 9, 18, 67};
    int data[8] = {10, 17, 20, 31, 32, 98, 54, 67};
    //swap(data, 3, 7);
    partition(data, 8, 0, 7);
    data;
	/*struct protoent *protocol;
	for(number=0; number<5; number++)
	{
		protocol = getprotobynumber(number);
		if(protocol == (struct protoent * ) NULL) continue;
		printf("%2d: %-10s: %-10s\n", protocol->p_proto, protocol->p_name, protocol->p_aliases[0]);
	}*/
	
}

