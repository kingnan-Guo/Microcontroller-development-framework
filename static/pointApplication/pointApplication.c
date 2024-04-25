/**
* pointApplication
 * 指针 应用
*/
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

//void point_application()
//{
//    printf("point2_fn \n");
//}
void point_application(int param){
    printf("point_application 1= %x\n", param);
    param = 0x88;
    printf("point_application 2= %x\n", param);
}


int findMax(int * arr){
    printf("arr == %x\n", arr);
    * arr = 0x04;
    return * (arr + 1);
}

// 使用 const 修饰 int * arr 的时候 ，这时 只读
int unChangeParams(const int * arr){
    printf("arr == %x\n", arr);
    // * arr = 0x04; 放开这句 程序会报错
    return * (arr + 1);
}

void findNumAndCount(int * data, int * arr, int * length){
    * data = arr[2];
    printf("sizeof(arr) = %x\n", sizeof(arr));
    * length = sizeof((* arr));// 这里获取出第一个 字节

}




int Time[] = {23, 59, 59 };

// 句柄
int * GetTime(void){
    return Time;
}



void point_application_main(void){
    printf("====== point_application_main ========\n");

    // 传递参数
    int a = 0x66;
    point_application(a);


    int arr[]={1, 2, 3,6};
    printf("sizeOf == %d\n", sizeof(arr) / 4);
    int Max = findMax(arr);
    printf("arr[0] == %d\n", arr[0]);
    printf("Max == %d\n", Max);



    unChangeParams(arr);

    int data;
    int length;
    findNumAndCount(&data, arr, &length);
    printf("data == %d\n", data);
    printf("length == %d\n", length);


    char str1[] = "hello World";
    char str2[20];
    printf("str1 == %s\n", str1);
    strcpy(str2, str1);
    printf("str2 == %s\n", str2);

    // 传递 返回值
    int *pt;
    pt = GetTime();
    printf("pt[0] == %d\n", pt[0]);
    printf("pt[1  ] == %d\n", pt[1]);

}