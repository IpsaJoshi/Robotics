#include <Wire.h>
const int MPU_addr=0x68,goffset=40;                    
int16_t GyX,GyY,GyZ;
int gZ_out,Zg;
float angleZ=0,angleZc=0;//,degree;
unsigned long s, t;
float dt=0.000;
float degree;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x68);                                                     // PWR_MGMT_1 register
  Wire.write(0);                                                        // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(19200);
}

void loop() {
  s=millis();
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x47);                                                     // starting with register 0x47 (GYRO_ZOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr,2,true);                                    // request a total of 2 registers
  
    GyZ=Wire.read()<<8|Wire.read();                                      // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
    GyZ=GyZ-goffset;
    Zg=GyZ/131;//angular velocity                                        // Dividing sensitivity
      
  t=millis()-s;
    
    dt=t/1000.0;
    angleZc = Zg*dt;
    angleZ = angleZ + angleZc;
    degree=angleZ*2.5;
    degree+=180;
   Serial.println(degree); 
  s=t=0; 
}
