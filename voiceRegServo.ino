#include <Servo.h>
boolean stopped, slow = false;
Servo servo;

void setup() {
  servo.attach(9);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {  
  String message;
  if (Serial.available() > 0) {
     message = Serial.readString();
  }
  if(message.equalsIgnoreCase("stop")) stopped = true;
  if(message.equalsIgnoreCase("go")) stopped = false;
  if(message.equalsIgnoreCase("slow")) slow = true;
  if(message.equalsIgnoreCase("fast")) slow = false;
  if(stopped) servo.write(60);
  if(slow && !stopped) servo.write(30);
  if(!stopped && !slow) servo.write(0);
  delay(300);
}
