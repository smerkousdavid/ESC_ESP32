/*
 * A simple class for control an ESC controller
 */ 
#include <ESP32Servo.h>
#include "ESC.h"

ESC::ESC(int pin, int mode){
  actualDirection = FORWARD;
  oPin = pin; // set pin for ESC
  setRunningMode(mode);
}

void ESC::setSpeed(unsigned int speed) {
  if(actualDirection == FORWARD && (baseSpeed + speed) < MAX_PULSE){
    writePulse(baseSpeed + speed);
  }else if ((baseSpeed - speed) > MIN_PULSE) {
    writePulse(baseSpeed - speed);
  }
}

void ESC::writePulse(unsigned int pulse) {
  // writes the microsecond pulse using ESP32Servo library
  esc.writeMicroseconds(pulse);
}

// borrowed from https://github.com/RB-ENantel/RC_ESC/blob/master/src/ESC.cpp
// useful only for forward only
void ESC::calibrate() {
  attach(oPin);
	esc.writeMicroseconds(MAX_PULSE);
	delay(CALIBRATION_DELAY);
	esc.writeMicroseconds(MIN_PULSE);
	delay(CALIBRATION_DELAY);
}

void ESC::arm() {
  attach(oPin);
  esc.writeMicroseconds(ARM_VALUE);
}

void ESC::setRunningMode(int mode) {
  if(mode == MODE_FORWARD_ONLY){
      baseSpeed = BASE_FORWARD_ONLY;
  }else if(mode == MODE_FORWARD_BACKWARD){
      baseSpeed = BASE_FORWARD_BACKWARD;
  }
}
void ESC::setDirection(int direction) {
  if(direction == FORWARD)
    actualDirection = FORWARD;
  else
    actualDirection = BACKWARD;
}

void ESC::detach() {
  esc.detach();
}

void ESC::attach(int pin) {
  esc.attach(pin);
  oPin = pin;
}
