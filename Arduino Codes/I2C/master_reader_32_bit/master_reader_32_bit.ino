2// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  int32_t bigNum;
  byte a,b,c,d;
  Wire.requestFrom(8, 4);   
  a=Wire.read();
  b=Wire.read();
  c=Wire.read();
  d=Wire.read();

  bigNum=a;
  bigNum=(bigNum << 8) | b;
  bigNum=(bigNum << 8) | c;
  bigNum=(bigNum << 8) | d;
  Serial.println(bigNum);
  //delay(500);
}
