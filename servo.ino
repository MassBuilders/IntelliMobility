#include <Servo.h>
boolean stopped, slow = false;
Servo servo;

void setup() {
  servo.attach(9); // White = signal, Black = negative, Red = positive
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {  
  if(digitalRead(2)) stopped = !stopped;
  else if (digitalRead(3)) slow = !slow;
  if(stopped) Serial.println("stopped true");
  else Serial.println("stopped false");
  if(slow) Serial.println("slow true");
  else Serial.println("slow false");
  if(stopped) servo.write(60);
  if(slow && !stopped) servo.write(30);
  if(!stopped && !slow) servo.write(0);
  delay(300);
}
