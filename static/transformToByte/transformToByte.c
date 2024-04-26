

/**
 * 打开文件
*/
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

unsigned char AirData[20];
void SendData(const unsigned char * data, unsigned char count){
    unsigned char i;
    for (i = 0; i < count; i++) {
        AirData[i] = data[i];
    }
}

void receiveData(unsigned char * data, unsigned char count){
    unsigned char i;
    for (i = 0; i < count; i++) {
        data[i] = AirData[i];
    }
}


void transformToByteMain(void){
    printf("====== transformToByteMain ========\n");



    unsigned char DataSend[] = {0x12, 0x34, 0x56};
    unsigned char count = (sizeof DataSend) / 1;
    SendData(DataSend, count);

    for (char i = 0; i < 10; ++i) {
        printf("AirData i= %x\n", AirData[i]);
    }


    unsigned char dataReceive[4];
    receiveData(dataReceive, 4);
    for (char i = 0; i < 4; ++i) {
        printf("dataReceive i= %x\n", dataReceive[i]);
    }

    // 指针会将复杂格式的数据 转换 为字节，方便通信和存储
    // float 类型是 4个字节的变量，只不过对其进行编码，以科学计数法来表示数据
    // 最高位 是符号位 ；由 阶码 尾码 储存 eg： 12.345 = 11
    float num = 3.1415;
    // 使用 指针依次 把四个字节的数据发送出去
    // num 是 首地址
    unsigned char * fp;
    //对 数据进行编码； 将 float 作为 四个字节的 char 数据发送出去
    fp = (unsigned char *)&num;

    SendData(fp, 4);
    for (char i = 0; i < 4; ++i) {
        printf("float to char  AirData i= %x\n", AirData[i]);
    }

    // 解码 使用 float *  = 这个传过来数据的首地址 ；把接收到的 四个字节 当作flaot 进行解码
    float * fpr;
    unsigned char dataReceive2[4];
    receiveData(dataReceive2, 4);
    for (char i = 0; i < 4; ++i) {
        printf("char to float dataReceive i= %x\n", dataReceive2[i]);
    }
    fpr = (float *)dataReceive2;
    printf("\nnum = %f", *fpr);

    return;
}

// 所有的数据都可以 使用 类型转换
