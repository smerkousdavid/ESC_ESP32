#include <ESP32Servo.h>
#include "ESC.h"

/* This example shows how to use serial to enter programming mode on your ESC controller.

  NOTE: YOU MUST HAVE YOUR ESP32 powered on BEFORE plugging in the ESC for programming

  STEPS:
  1. Unplug your ESC controller
  2. Flash ESP32 with this INO
  3. Reset your ESP32
  4. Open your Serial monitor and prepare to send either 0 (for neutral mode) or 1 (for "max power" mode).
  5. Follow your ESC datasheet to reprogram your controller using a "controller".
      Anytime it says put controller in neutral send a 0 in serial monitor.
      Anytime it says put controller in full throttle send a 1 in serial monitor.
  6. Plug in your ESC and follow specified instructions

  For example to ENABLE Forward and Reverse on the Turnigy Marine 50A follow these steps.
  1. Plug in your ESC and wait for 2 beeps (depending on model) then wait for 5 seconds until you hear a fun tone (again read your ESC datasheet).
  2. Then you'll hear 5 different groups of tones on repeat. First a beep pause, but wait for the beep beep pause then immediately send 0.
  3. Then you will hear another set of tones that will repeat. First a short beep and then two short beeps. Once it reaches two short beeps immediately send 1.
  4. Wait for a set tone (should sound like a jingle) to finish indicating you have set the forward/reverse mode on
  5. Unplug your ESC
  6. That's it your ESC is now enabled for forward/reverse when you plug it in
 */

#define ESC_PIN 25
#define ESC_MAX_PULSE 2000
#define ESC_NEUTRAL_PULSE 1000

ESC esc(ESC_PIN, ESC::MODE_FORWARD_ONLY);

void setup() {
  Serial.begin(9600);

  esc.attach(ESC_PIN); // note we don't use arm for this one since we want 2000 msec pulses immediately
  esc.writePulse(ESC_MAX_PULSE);
} 
 
void loop() { 
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '0') {
      Serial.println("ZERO");
      esc.setSpeed(0);
    } else if (c == '1') {
      Serial.println("FULL");
      esc.setSpeed(FULL_SPEED);
    }
  }
} 