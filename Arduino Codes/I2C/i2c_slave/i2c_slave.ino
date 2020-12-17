#include<wire.h>
int x;

void setup() {
  Wire.begin(7);
  Serial.begin(9600);

}

void loop() {
  x=Wire.read();

}
