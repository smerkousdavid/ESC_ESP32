#include <ESP32Servo.h>
#include "ESC.h"

#define ESC_PIN 25

/* This example shows how to use an ESC controller that can go
 * only forward
 */
ESC esc(ESC_PIN);

void setup() 
{ 
    esc.arm();
    esc.setSpeed(30);
    vTaskDelay(1000);
    esc.setSpeed(0);
    vTaskDelay(1000);
    esc.setSpeed(35);
    vTaskDelay(1000);
    esc.setSpeed(0);  
} 
 
void loop() 
{ 

} 
