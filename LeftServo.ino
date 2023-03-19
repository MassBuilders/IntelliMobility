#include <Servo.h>
boolean stopped;
int wait = 1500;
int slowLeft = 3;
boolean slowL = false;
int brake = 5;
unsigned long currTime = 0;
Servo servo;

void setup() {
  servo.attach(9); // White = signal, Black = negative, Red = positive
  pinMode(slowLeft, INPUT);
  pinMode(brake, INPUT);
  Serial.begin(9600);
}

void loop() {  
//  if(millis() >= currTime + wait && digitalRead(slowLeft)) {
//    currTime += wait;
//    slowL = !slowL;
//  }
  if(millis() >= currTime + wait && digitalRead(brake) {
     currTime += wait;
    stopped = !stopped;
  }
  if(stopped) {
    servo.write(100); // servoLeft
  } else if(digitalRead(slowLeft)) {
    servo.write(109); // servoLeft
  } else {
    servo.write(140); // servoLeft
  }
}
