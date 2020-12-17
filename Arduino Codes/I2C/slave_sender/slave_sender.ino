//slave sender high low byte
#include <Wire.h>
int x=0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  //delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {

  Wire.write(lowByte(x)); // respond with message of 6 bytes
  Wire.write(highByte(x));
  x+=100;
 
}
