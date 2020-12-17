//arduino nano master
#include<wire.h>
int x=0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(7);
  wire.write(x);
  wire.endTransmission();
  x++;

}
