#include <stdio.h>


void point_fn()
{
    printf("point \n\r");

    int a = 0xA3; // 定义一个数字， 储存在内存的 某处
    char b;//定义 一个 char， 储存在内存的 某处
    int  * p;// 表示 p 为 int * 类型；  因为 指针也是变量，所以 储存在 内存的某处，占用 8 个字节
    printf("sizeof int = %lu\n", sizeof(a));
    printf("sizeof char = %lu\n", sizeof(b));
    printf("sizeof int * = %lu\n", sizeof(p));




    printf("p =  %ul\n", p);
    printf("&p = p的地址  %x\n", &p);// %x 16 进制；
    p = &a;// 把 a 的地址取出来 存到  p 指针变量里
    printf("p = a 的地址 %x\n", p);

    printf("p = 取出 p 变量内保存的地址 对应的 内容 %x\n", *p);

    p++;// p++ 是将 增加一个数据宽度
    printf("%x\n", p);// 因为 int 为 4 字节，所以 p++ 是将 增加一个数据宽度， 加4个字节 ；所以  &a + 4 = p++


    char arr[] = {0x32, 0x34,0x36};
    printf("arr = %x\n", arr);
    printf("*arr = %x\n", *arr);
    printf(" arr[0] = %x\n", arr[0]);

    printf("*(arr + 1) = %x\n", *(arr + 1));
    printf("*(arr + 2) = %x\n", *(arr + 2));
    printf("&arr = %x\n", &arr);

    char * arrP;
    arrP = arr;// 数组的首地址 给了指针
    printf("arrP = %x\n", arrP);
    printf("* arrP = %x\n",* arrP);
    printf("* (arrP + 1) = %x\n",* (arrP + 1));
    printf("(arrP + 1) = %x\n", (arrP + 1));
    printf("(arrP++) = %x\n", (arrP++));//  arrP = arrP  + 1; 不会报错
    printf("(arr + 1) = %x\n", (arr + 1));// arr = arr+1; 会报错
}



