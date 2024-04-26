
/**
 * 打开文件
*/
#include <stdio.h>
#include "stdlib.h"
#include "string.h"


void writeFile(void){
    FILE * f = fopen("/Users/kingnan/Documents/github/Microcontroller-development-framework/file/text.txt", "w");
    fputc('A', f);
    fputs("fileOpenMain2", f);
    fclose(f);
}


void readFile(void){
    char fileStr;
    char strs[10];
    FILE * f = fopen("/Users/kingnan/Documents/github/Microcontroller-development-framework/file/text.txt", "r");
    fileStr = fgetc(f);

    fgets(strs, 10, f);
    fclose(f);
    printf("fileStr = %c\n",fileStr);
    printf(strs);
    printf("\n");
}

void fileOpenMain(void){
    printf("====== fileOpenMain ========\n");

//    writeFile();

    readFile();

    return;
}