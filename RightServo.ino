#include <Servo.h>
boolean stopped;
int wait = 1500;
int slowRight = 3;
boolean slowR = false;
int brake = 5;
unsigned long currTime = 0;
Servo servo;

void setup() {
  servo.attach(11); // White = signal, Black = negative, Red = positive
  pinMode(slowRight, INPUT);
  pinMode(brake, INPUT);
  Serial.begin(9600);
}

void loop() {  
//  if(millis() >= currTime + wait && digitalRead(slowRight)) {
//    currTime += wait;
//    slowR = !slowR;
//  }
  if(millis() >= currTime + wait && digitalRead(brake)) {
    currTime += wait;
    stopped = !stopped;
  }
  if(stopped) {
    servo.write(50);
  } else if(digitalRead(slowRight)) {
    servo.write(22);
  } else {
    servo.write(0);
  }
}
