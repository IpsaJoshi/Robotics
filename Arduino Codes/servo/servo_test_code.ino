#include <Servo.h>
Servo myservo;

void setup() {
myservo.attach(39);
}

void loop() {
  myservo.write(30);
}
