#include "Motion.h"
#include "Applyspd.h"
#include "GY80.h"
#include <Wire.h>
#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
//------------------------------------------------------PS3---------------------------------------------------------
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
//-----------------------------------------------------Motion-------------------------------------------------------
int  LSmot1 = 31,LSmot2 = 33;
int  LSmot5 = 11;
int LSspd ;
//---------------------------------------------------PID-------------------------------------------------------------------


//-------------------------------------------------Classes-------------------------------------------------------
USB Usb;
BTD Btd(&Usb); 
PS3BT PS3(&Btd);

Motion spd;
Applyspd apply;


//-------------------------------------------------
void setup() {
   pinMode(LSmot1,OUTPUT);   pinMode(LSmot2,OUTPUT); 
      pinMode(LSmot5,OUTPUT);   

 
#if !defined(__MIPSEL__)
  while (!Serial); 
#endif
  if (Usb.Init() == -1) {
    while (1); 
  }
 Serial.begin(115200);
 }

void loop() {
 
   Usb.Task();
   
   if (PS3.PS3Connected) {
      
        if(up)LSspd=100;
        else if(down)LSspd=-100;
        else{  LSspd=0;}
        LSapplyspd();
       
        Serial.print(" lspd=");Serial.println(LSspd);
       // Serial.print(" spd1=");Serial.print(spd1);Serial.print(" spd2=");Serial.print(spd2);Serial.print(" spd3=");Serial.println(spd3);
     }
    

}
