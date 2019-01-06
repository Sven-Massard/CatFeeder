#include <Arduino.h>
#include <Servo.h>
#include "IRremote.h"
Servo servo;
#define POWER 0x7F80
#define AIWA_RC_T501
#define BUTTON 6
#define RECV_PIN 8
#define SERVOPIN 9

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
  irrecv.enableIRIn();
  servo.attach(SERVOPIN);
  servo.write(180);
  delay(1000);
  servo.detach();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    servo.attach(SERVOPIN);
    servo.write(30);
    delay(575);
    servo.write(180);
    delay(1500);
    servo.detach();
    irrecv.resume(); // Receive the next value
  }
}