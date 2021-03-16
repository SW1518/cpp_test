#include <iostream>

int main(int argc, char *argv[])
{
    int arr[2][3] {1,2,3,
                   4,5,6};
    int (*p)[3] = arr;
    std::cout<<*(*(p+1))<<std::endl;
    std::cout<<*(*p+1)<<std::endl;

    const char* str[] ={"hello","world"};
    const char str1[] = {"hello"};
    const char **pchar {nullptr};
    pchar = str;
    std::cout<<*pchar+1<<std::endl;
    std::cout<<*(pchar+1)<<std::endl;
}