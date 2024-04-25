#include <stdio.h>
#include "stdlib.h"

void point_fn2()
{
    printf("point2_fn \n");

    // 申请一块内存 ； size: 3个变量 * 4 个字节；
    // 返回值是 void * ； 因为在申请的时候并不知道 是 要装什么值， 可以使用int * 来接收返回值
    int * addr = malloc(3 * 4);
    printf("addr %x\n", addr);
    printf("* addr %x\n", * addr);// 未安装任何值 所以返回 0

    * addr = 0x33;
    printf("* addr %x\n", * addr);


    printf("& addr %x\n", & addr);
//    printf("&& addr %x\n", && addr);
}



