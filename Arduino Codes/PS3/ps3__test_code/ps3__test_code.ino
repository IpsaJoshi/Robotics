//3- wheel 360 mapping


/*******  JOYSTICK CONFIG *****************/
#define Joy_left_x PS3.getAnalogHat(LeftHatX)
#define Joy_left_y PS3.getAnalogHat(LeftHatY)
#define Joy_right_x PS3.getAnalogHat(RightHatX)
#define Joy_right_y PS3.getAnalogHat(RightHatY)
#define l2 PS3.getAnalogButton(L2)
#define r2 PS3.getAnalogButton(R2)
#define ps PS3.getButtonPress(PS)
#define l1 PS3.getButtonPress(L1)
#define l3 PS3.getButtonPress(L3)
#define r3 PS3.getButtonPress(R3)
#define r1 PS3.getButtonPress(R1)
#define up PS3.getButtonPress(UP)
#define down PS3.getButtonPress(DOWN)
#define left PS3.getButtonPress(LEFT)
#define right PS3.getButtonPress(RIGHT)
#define triangle PS3.getButtonPress(TRIANGLE)
#define circle PS3.getButtonPress(CIRCLE)
#define cross PS3.getButtonPress(CROSS)
#define square PS3.getButtonPress(SQUARE)
#define select PS3.getButtonPress(SELECT)
#define startb PS3.getButtonPress(START)

#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

PS3BT PS3(&Btd); // This will just create the instance

/*****************************************************************************************************/

/**************************************************************************************/

void setup(){
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
   // Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
 Serial.begin(9600);
}

/*****************************************************************************************************************************************/
void loop() {
 Usb.Task();
if (PS3.PS3Connected) {
  

  }
}
