#include <Stepper.h>
const int stepsPerRevolution = 4;  // Stepper has 400 revolutions
Stepper myStepper(stepsPerRevolution, 3,11,12,13); // See reference for ARDUMOTO- use pins 3,11,12,13
int pinDirZa=7;
int pinDirZb=8;
int pinPwmZa = 9;
int pinPwmZb = 6;
int speedZ=50;
void setup() {
  myStepper.setSpeed(1000);  // set the speed at 70 rpm:
  // 70 is a nice fluid move  60-70 rpm, and a nice slow rotation could be 20
  pinMode(pinDirZa,OUTPUT);
  pinMode(pinDirZb,OUTPUT);
  pinMode(pinPwmZa,OUTPUT);
  pinMode(pinPwmZb,OUTPUT);
}

void loop() {
    myStepper.step(stepsPerRevolution); // Do a full revolution, 400 steps
    digitalWrite(pinDirZa,HIGH);
    digitalWrite(pinPwmZa,HIGH);
    delay(speedZ);
    digitalWrite(pinPwmZa,LOW);
    digitalWrite(pinDirZa,LOW);
    
    digitalWrite(pinDirZb,HIGH);
    digitalWrite(pinPwmZb,HIGH);
    delay(speedZ);
    digitalWrite(pinPwmZb,LOW);
    digitalWrite(pinDirZb,LOW);
    
    
    digitalWrite(pinPwmZa,HIGH);
    delay(speedZ);
    digitalWrite(pinPwmZa,LOW);
    
    digitalWrite(pinPwmZb,HIGH);
    delay(speedZ);
    digitalWrite(pinPwmZb,LOW);
    
    
//delay(1000);
}
