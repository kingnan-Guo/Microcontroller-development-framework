//VERSION 1.0.1 TIME 
//加入DS18B20传感器测试模块
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <queue.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "DS18B20.h"
#define FIRST_GPIO 2
#define QUEUE_LEN 4//队列的长度,最大包含多少消息
#define QUEUE_SIZE 4//队列中每个消息的字节
int Temperature_temp=0;
int bits[10] = {//共阴极7段数码管
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x6f   // 9
};
QueueHandle_t Test_Queue1=NULL;
void task1(void *pvParameters){
    while(true){
        const float conversion_factor=3.3f/(1<<12);
        float adc=(float)adc_read()*conversion_factor;
        float Temperature=27 - (adc - 0.706)/0.001721;
        int Temperature_temp=(int)(Temperature*100);

        printf("发送队列消息Temperature\n");
        xQueueSend(Test_Queue1,&Temperature_temp,0);

        printf("voltage: %f V\nOn board Temperature: %f Degree\n",adc,Temperature);   
        // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
        vTaskDelay(2000);
    }
}
void task2(void *pvParameters){
    while(true){
        int a,b,c,d;
        xQueueReceive(Test_Queue1,&Temperature_temp,1);
        a=Temperature_temp/1000;
        b=Temperature_temp/100-a*10;
        c=Temperature_temp/10-a*100-b*10;
        d=Temperature_temp-a*1000-b*100-c*10;
        int32_t mask = bits[a] << FIRST_GPIO;//掩码
        // Set all our GPIOs in one go!
        // If something else is using GPIO, we might want to use gpio_put_masked()
        gpio_set_mask(mask);
        gpio_put(9,0);
        gpio_put(10,0);
        gpio_put(11,1);
        gpio_put(12,1);
        gpio_put(13,1);
        vTaskDelay(5);
        gpio_clr_mask(mask);  //清除上一次的值
        
        mask = bits[b] << FIRST_GPIO;//掩码
        gpio_set_mask(mask);
        gpio_put(9,1);
        gpio_put(10,1);
        gpio_put(11,0);
        gpio_put(12,1);
        gpio_put(13,1);
        vTaskDelay(5);
        gpio_clr_mask(mask);  //清除上一次的值 
        
        mask = bits[c] << FIRST_GPIO;//掩码
        gpio_set_mask(mask);
        gpio_put(9,0);
        gpio_put(10,1);
        gpio_put(11,1);
        gpio_put(12,0);
        gpio_put(13,1);
        vTaskDelay(5);
        gpio_clr_mask(mask);  //清除上一次的值     

        mask = bits[d] << FIRST_GPIO;//掩码
        gpio_set_mask(mask);
        gpio_put(9,0);
        gpio_put(10,1);
        gpio_put(11,1);
        gpio_put(12,1);
        gpio_put(13,0);
        vTaskDelay(5);
        gpio_clr_mask(mask);  //清除上一次的值 
    }

}
void task3(void *pvParameters){//DS18B20传感器测温任务
  while(true){
        ReadTemperature();
        vTaskDelay(2000);

  }
}
int main(){

    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN);//初始化板载LED，表征进入主程序
    gpio_set_dir(PICO_DEFAULT_LED_PIN,GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN,1);
    gpio_init(DQ_PIN);//初始化外设温度器数据引脚GPIO22
    gpio_set_dir(DQ_PIN,GPIO_OUT);

    //初始化8段数码管GPIO引脚
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 12; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        // Our bitmap above has a bit set where we need an LED on, BUT, we are pulling low to light
        // so invert our output
        //gpio_set_outover(gpio, 1);
    }
     
    printf("ADC Meausring GPIO026\n");
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);//temperature
    xTaskCreate(task1, "ADC_Task", 256, NULL, 1, NULL); 
    xTaskCreate(task2, "SEG_Task", 256, NULL, 1, NULL);
    xTaskCreate(task3,"DS18B20_Task",256,NULL,1,NULL);
    Test_Queue1=xQueueCreate(QUEUE_LEN,QUEUE_SIZE);  
    vTaskStartScheduler();

    while(true){};
}



