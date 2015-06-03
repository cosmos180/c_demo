#include "stdafx.h"
#include <time.h>
#include <string>
#include <stdarg.h>
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


static void permutation(char *str, char *pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", str);
    }
    else
    {
        for (char *pCh= pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            permutation(str, pBegin+1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void permutation( char *str )
{
    if (str == NULL)
        return;
    permutation(str, str);
}

/************************************************************************/
/* 可变长参数                                                           */
/************************************************************************/
void printfVariousData( wchar_t *fmt, ... )
{
    TCHAR zBuffer[20] = {0};
    //int nSize = 0;
    int ret = 0;
    va_list lsArgs;

    va_start(lsArgs, fmt);
#ifdef _UNICODE
    /*vswprintf(zBuffer, _TRUNCATE, fmt, lsArgs);*/
    ret = _vsnwprintf_s(zBuffer, _TRUNCATE, fmt, lsArgs);
#else
    vsnprintf(zBuffer, _TRUNCATE, fmt, lsArgs);
#endif
    va_end(lsArgs);
    wprintf(zBuffer);
    return;

    wchar_t buffer[512] = {0};
    va_list ap;
    int d=0, len=0, nTotalLen = 0;
    wchar_t c= L'\0', *p=NULL, *s=NULL;
    va_start(ap, fmt);
    while(*fmt)
    {
        if (*fmt == L'%')
        {
            switch(*(++fmt))
            {
            case L's':
                s = va_arg(ap, wchar_t*);
                len = wcslen(s);
                memcpy(buffer+nTotalLen, s, len * sizeof(wchar_t));
                nTotalLen += len;
                buffer[nTotalLen] = 0;
                break;
            case L'c':
                c = va_arg(ap, int);
                memcpy(buffer+nTotalLen, &c, 1 * sizeof(wchar_t));
                nTotalLen += 1;
                buffer[nTotalLen] = 0;
                break;
            case L'd':
                c = va_arg(ap, int);
                len = _snwprintf_s(buffer+nTotalLen, 4, _TRUNCATE, L"%d", c);
                nTotalLen += len;
                buffer[nTotalLen] = 0;
                break;
            case L'%':
                memcpy(buffer+nTotalLen, L"%%", 2 * sizeof(wchar_t));
                nTotalLen += 2;
                buffer[nTotalLen] = 0;
                break;
            default:
                c = va_arg(ap, int);
                memcpy(buffer+nTotalLen, &c, 1 * sizeof(wchar_t));
                nTotalLen += 1;
                buffer[nTotalLen] = 0;

                //memcpy(buffer+nTotalLen, L"%%", 2 * sizeof(wchar_t));
                //nTotalLen += 2;
                //--fmt;
                //memcpy(buffer+nTotalLen, fmt, 2 * sizeof(wchar_t));
                //nTotalLen += 2;
                //buffer[nTotalLen] = 0;
                //fmt++;
                //c = *(--fmt);
                //memcpy(buffer+nTotalLen, fmt, 1 * sizeof(wchar_t));
                //nTotalLen += 1;
                //buffer[nTotalLen] = 0;

                //c = *(++fmt);
                //memcpy(buffer+nTotalLen, fmt, 1 * sizeof(wchar_t));
                //nTotalLen += 1;
                //buffer[nTotalLen] = 0;
            }
        }
        else
        {
            c = *fmt;
            memcpy(buffer+nTotalLen, &c, 1 * sizeof(wchar_t));
            nTotalLen += 1;
            buffer[nTotalLen] = 0;
        }
        ++fmt;
    }
    va_end(ap);
    wprintf(buffer);
}


