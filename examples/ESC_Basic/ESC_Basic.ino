#include <ESP32Servo.h>

#include "ESC.h"

#define ESC_PIN 9

/* This example shows how to use an ESC controller that can go
 * only forward
 */
ESC esc;

void setup() 
{ 
    esc.attach(ESC_PIN);
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
