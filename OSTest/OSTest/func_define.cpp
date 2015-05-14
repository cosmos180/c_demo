#include "stdafx.h"
#include <time.h>
#include <string>
#include "func_declare.h"


void comparePerformancezWithBit()
{
    int a = 1234567;
    int time = 5000000;
    double start = (double)clock();
    for(int i=0;i<time;++i)
    {
        a = a << 1;
    }
    double end = (double)clock();
    printf("==========\n bit operate: %f\n==========\n",end - start);

    a = 1234567;
    start = (double)clock();
    for(int i= 0;i<time;++i)
    {
        a = a * 2;
    }   
    end = (double)clock();
    printf("==========\n multiple operate: %f\n==========\n",end - start);

    start = (double)clock();
    for(int i=0;i<time;++i)
    {
        a = a >> 1;
    }
    end = (double)clock();
    printf("==========\n bit operate: %f\n==========\n",end - start);

    a = 1234567;
    start = (double)clock();
    for(int i= 0;i<time;++i)
    {
        a = a / 2;
    }   
    end = (double)clock();
    printf("==========\n division operate: %f\n==========\n",end - start);
}



//void printToMaxOfDigits( int n )
//{
//    int number=1, i=0;
//    while(i++ < n)
//        number *= 10;
//
//    for(i=1; i<number; i++)
//        printf("%d\t", i);
//}

void printNumber(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for (int i=0; i<nLength; i++)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }
}

void PrintToMaxOfNDigitsRecursively(char *number, int length, int index)
{
    if (index == length - 1)
    {
        printNumber(number);
        return;
    }

    for (int i=0; i<10; ++i)
    {
        number[index+1] = i + '\0';
        PrintToMaxOfNDigitsRecursively(number, length, index);
    }
}

void printToMaxOfDigits( int n )
{
    if (n <= 0)
        return;
    char *number = new char[n+1];
    number[n] = '\0';

    for (int i=0; i<10; ++i)
    {
        number[0] = i + '\0';
        printf("%c \t", number);
        //PrintToMaxOfNDigitsRecursively(number, n, 0);
    }


    //printNumber(number);

    delete []number;
}