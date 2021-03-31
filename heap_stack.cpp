#include <stdlib.h>
#include <string.h>
#include <iostream>
int a = 0; //全局初始化区
char *p1; //全局未初始化区
main()
{
    //内存操作
    const char a[] = "xixihaha";
    const char *p = a;
    std::cout<<*p+1<<std::endl;
    int num {100};
    int addr {200};
    int *pInt = reinterpret_cast<int*>(&addr);
    //int alpha = reinterpret_cast<int>(&addr); // wrong type
    int alpha = reinterpret_cast<int>(addr);// new address
    *pInt = num;
    int b; //栈
    char s[] = "abc"; //栈
    char *p2; //栈
    const char *p3 = "123456"; //123456在常量区，p3在栈上。
    static int c = 0; //全局（静态）初始化区
    p1 = (char *)malloc(10);
    p2 = (char *)malloc(20);
    //分配得来得10和20字节的区域就在堆区。
    strcpy(p1, "123456"); //123456放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。
    int &beta = num;
}