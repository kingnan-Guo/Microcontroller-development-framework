
/**
 * 打开文件
*/
#include <stdio.h>
#include "stdlib.h"
#include "string.h"



void fileOpenMain(void){
    printf("====== fileOpenMain ========\n");

    FILE * f = fopen("/Users/kingnan/Documents/github/Microcontroller-development-framework/file/text.txt", "w");
    fputc('A', f);
    fputs("fileOpenMain2", f);
    fclose(f);

    return;
}