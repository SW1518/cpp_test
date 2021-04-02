#include <iostream>

int main(int argc, char *argv[])
{
    int arr[2][3] {1,2,3,
                   4,5,6};
    int (*p)[3] = arr;
    std::cout<<**(p+1)<<std::endl;
    std::cout<<**p+1<<std::endl;
    std::cout<<*(*(p+1))<<std::endl;
    std::cout<<*(*p+1)<<std::endl;

    const char* str[] ={"hello","world"};
    const char str1[] = {"hello"};
    const char **pchar {nullptr};
    pchar = str;
    std::cout<<*pchar+1<<std::endl;
    std::cout<<*(pchar+1)<<std::endl;

    int multi_arr[32] {0,1,2,3,4,5,6,7,8,9,10,
                 11,12,13,14,15,16,17,18,19,20,
                 21,22,23,24,25,26,27,28,29,30,
                 31};
    int *pcout = multi_arr;
    pcout += 31;
    std::cout<<*pcout<<std::endl;
}