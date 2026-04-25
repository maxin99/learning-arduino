#include <Arduino.h>
#include <Servo.h>

/*
This file includes a simple test for a servo that goes from 0-180 
It is an SG90
 */

Servo servo;

void setup() {
  servo.attach(9);
}


void loop() {
  servo.write(0);
  delay(1000);

  servo.write(45); 
  delay(1000);

  servo.write(90); 
  delay(1000);

  servo.write(125); 
  delay(1000);

  servo.write(180); 
  delay(1000);

}