// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
int32_t bigNum=0;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
 // delay(100);
 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  bigNum+=1000;
  byte myArray[4];

  myArray[0] = (bigNum >> 24) & 0xFF;
  myArray[1] = (bigNum >> 16) & 0xFF;
  myArray[2] = (bigNum >> 8) & 0xFF;
  myArray[3] =  bigNum &0xFF;
  Wire.write(myArray,4);
  
  
}
