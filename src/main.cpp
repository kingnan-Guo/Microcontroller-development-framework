#include <iostream>
// #include <fmt/format.h>

// #include <evolution.h>

extern "C" {
    #include <evolution.h>
    // #include <FreeRTOS.h>
    // #include <task.h>
    // #include <queue.h>
    // #include <timers.h>
    // #include <semphr.h>


    // #include "FreeRTOSConfig.h"
    #include <FreeRTOS.h>
    #include <task.h>
    #include <queue.h>
    #include <timers.h>
    #include <semphr.h>
    // #include <stdio.h>
}


void task1(void *pvParameters){
    // printf("发送队列消息Temperature\n");
    // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
    // vTaskDelay(2000);
}

// void traceRETURN_vTaskStartScheduler()
// {
//     std::cout << "traceRETURN_vTaskStartScheduler" << std::endl;
//     return;
// }



void exampleTask( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;
    std::cout << "Hello, world!" << std::endl;
    return;

}

int main(){

    static StaticTask_t exampleTaskTCB;
    static StackType_t exampleTaskStack[ configMINIMAL_STACK_SIZE ];

    printf( "Example FreeRTOS Project\n" );
    evo_fn();
    xTaskCreateStatic( exampleTask,
                       "example",
                       configMINIMAL_STACK_SIZE,
                       NULL,
                       configMAX_PRIORITIES - 1,
                       &( exampleTaskStack[ 0 ] ),
                       &( exampleTaskTCB ) );

    // /* Start the scheduler. */
    vTaskStartScheduler();

    // xTaskCreate(task1, "ADC_Task", 256, NULL, 1, NULL); 
    // vTaskStartScheduler();
    
    
    return 0;
}


void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
     * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;
}
/*-----------------------------------------------------------*/



