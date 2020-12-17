/**************************************************************************
*                                                                         *
* GY-80 Driver for Arduino                                              *
*                                                                         *
***************************************************************************
*                                                                         * 
* This program is free software; you can redistribute it and/or modify    *
* it under the terms of the GNU License.                                  *
* This program is distributed in the hope that it will be useful,         *
* but WITHOUT ANY WARRANTY; without even the implied warranty of          *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
* GNU License V2 for more details.                                        *
*                                                                         *
***************************************************************************/
#include "Arduino.h"
#include <GY80.h>

#define ADXL345_DEVICE (0x53)    // ADXL345 I2C address
#define L3G4200D_DEVICE (0x69)	 // L3G4200D I2C address
#define HMC5883_DEVICE (0x1E)	 // HMC5883 I2C address
#define BMP085_DEVICE (0x77)	 // BMP085 I2C address

GY80::GY80(){
	Wire.begin();
}

void GY80::setupGyro(int scale){
	// From Jim Londblum - sparkfun

	// Enable x, y, z and turn off power down:
	writeRegister(L3G4200D_DEVICE, CTRL_REG1, 0b00001111);

	// If you'd like to adjust/use the HPF, you can edit the line below to configure CTRL_REG2:
	writeRegister(L3G4200D_DEVICE, CTRL_REG2, 0b00000000);

	// Configure CTRL_REG3 to generate data ready interrupt on INT2
	// No interrupts used on INT1, if you'd like to configure INT1
	// or INT2 otherwise, consult the datasheet:
	writeRegister(L3G4200D_DEVICE, CTRL_REG3, 0b00001000);

	// CTRL_REG4 controls the full-scale range, among other things:

	if(scale == 250){
		writeRegister(L3G4200D_DEVICE, CTRL_REG4, 0b00000000);
	}else if(scale == 500){
		writeRegister(L3G4200D_DEVICE, CTRL_REG4, 0b00010000);
	}else{
		writeRegister(L3G4200D_DEVICE, CTRL_REG4, 0b00110000);
	}

	// CTRL_REG5 controls high-pass filtering of outputs, use it
	// if you'd like:
	writeRegister(L3G4200D_DEVICE, CTRL_REG5, 0b00000000);
}

void GY80::setupAcc(void){
	writeRegister(ADXL345_DEVICE, ADXL345_POWER_CTL, 0);
	writeRegister(ADXL345_DEVICE, ADXL345_POWER_CTL, 16);
	writeRegister(ADXL345_DEVICE, ADXL345_POWER_CTL, 8);
}

void GY80::setupMag(void){
	writeRegister(HMC5883_DEVICE, HMC5883_MODE_CTL, 0);
	writeRegister(HMC5883_DEVICE, HMC5883_SAMPLERATE_CTL, 0b00011000);
}

void GY80::setupTemp(void){
	ac1 = readRegister(BMP085_DEVICE, 0xAA) << 8 | readRegister(BMP085_DEVICE, 0xAB);
  	ac2 = readRegister(BMP085_DEVICE, 0xAC) << 8 | readRegister(BMP085_DEVICE, 0xAD);
  	ac3 = readRegister(BMP085_DEVICE, 0xAE) << 8 | readRegister(BMP085_DEVICE, 0xAF);
  	ac4 = readRegister(BMP085_DEVICE, 0xB0) << 8 | readRegister(BMP085_DEVICE, 0xB1);
  	ac5 = readRegister(BMP085_DEVICE, 0xB2) << 8 | readRegister(BMP085_DEVICE, 0xB3);
  	ac6 = readRegister(BMP085_DEVICE, 0xB4) << 8 | readRegister(BMP085_DEVICE, 0xB5);
  	b1  = readRegister(BMP085_DEVICE, 0xB6) << 8 | readRegister(BMP085_DEVICE, 0xB7);
  	b2  = readRegister(BMP085_DEVICE, 0xB8) << 8 | readRegister(BMP085_DEVICE, 0xB9);
  	mb  = readRegister(BMP085_DEVICE, 0xBA) << 8 | readRegister(BMP085_DEVICE, 0xBB);
  	mc  = readRegister(BMP085_DEVICE, 0xBC) << 8 | readRegister(BMP085_DEVICE, 0xBD);
  	md  = readRegister(BMP085_DEVICE, 0xBE) << 8 | readRegister(BMP085_DEVICE, 0xBF);
}

void GY80::setupPress(void){


}

void GY80::writeRegister(int deviceAddress, byte address, byte val) {
    Wire.beginTransmission(deviceAddress); // start transmission to device 
    Wire.write(address);       // send register address
    Wire.write(val);         // send value to write
    Wire.endTransmission();     // end transmission
}

int GY80::readRegister(int deviceAddress, byte address){

    int v;
    Wire.beginTransmission(deviceAddress);
    Wire.write(address); // register to read
    Wire.endTransmission();

    Wire.requestFrom(deviceAddress, 1); // read a byte

    while(!Wire.available()) {
        // waiting
    }

    v = Wire.read();
    return v;
}

void GY80::getAcc(int *x, int *y, int *z){
	byte xMSB = readRegister(ADXL345_DEVICE, ADXL345_DATAX1);
	byte xLSB = readRegister(ADXL345_DEVICE, ADXL345_DATAX0);
	*x = ((xMSB << 8) | xLSB);

	byte yMSB = readRegister(ADXL345_DEVICE, ADXL345_DATAY1);
	byte yLSB = readRegister(ADXL345_DEVICE, ADXL345_DATAY0);
	*y = ((yMSB << 8) | yLSB);

	byte zMSB = readRegister(ADXL345_DEVICE, ADXL345_DATAZ1);
	byte zLSB = readRegister(ADXL345_DEVICE, ADXL345_DATAZ0);
	*z = ((zMSB << 8) | zLSB);
}

void GY80::getGyro(int *x, int *y, int *z){
	byte xMSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAX1);
	byte xLSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAX0);
	*x = ((xMSB << 8) | xLSB);

	byte yMSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAY1);
	byte yLSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAY0);
	*y = ((yMSB << 8) | yLSB);

	byte zMSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAZ1);
	byte zLSB = readRegister(L3G4200D_DEVICE, L3G4200D_DATAZ0);
	*z = ((zMSB << 8) | zLSB);
}

void GY80::getMag(int *x, int *y, int *z){
	byte xMSB = readRegister(HMC5883_DEVICE, HMC5883_DATAX0);
	byte xLSB = readRegister(HMC5883_DEVICE, HMC5883_DATAX1);
	*x = ((xMSB << 8) | xLSB);

	byte yMSB = readRegister(HMC5883_DEVICE, HMC5883_DATAY0);
	byte yLSB = readRegister(HMC5883_DEVICE, HMC5883_DATAY1);
	*y = ((yMSB << 8) | yLSB);

	byte zMSB = readRegister(HMC5883_DEVICE, HMC5883_DATAZ0);
	byte zLSB = readRegister(HMC5883_DEVICE, HMC5883_DATAZ1);
	*z = ((zMSB << 8) | zLSB);
}

void GY80::getTemp(int *t){
	writeRegister(BMP085_DEVICE, BMP085_START_CTL, 0x2E); // start temperature measurement

	byte tMSB = readRegister(BMP085_DEVICE, BMP085_DATAT1);
	byte tLSB = readRegister(BMP085_DEVICE, BMP085_DATAT0);
	*t = ((tMSB << 8) | tLSB);
}

long GY80::convertToTemp(int t){
	long x1, x2;
	x1 = (((long)t - (long)ac6)*(long)ac5) >> 15;
  	x2 = ((long)mc << 11)/(x1 + md);
  	b5 = x1 + x2;

  	return  ((b5 + 8)>>4);  
}

void GY80::getPress(int *p){
	writeRegister(BMP085_DEVICE, BMP085_START_CTL, 0x37); // Configure pressure measurement for highest resolution
	byte pMSB = readRegister(BMP085_DEVICE, BMP085_DATAT2);
	byte pNSB = readRegister(BMP085_DEVICE, BMP085_DATAT1);
	byte pLSB = readRegister(BMP085_DEVICE, BMP085_DATAT0);
	*p = ((pMSB << 16) | (pNSB << 8) | pLSB);
}

long GY80::convertToPress(int up){
  long x1, x2, x3, b3, b6, p;
  unsigned long b4, b7;
  
  b6 = b5 - 4000;
  // Calculate B3
  x1 = (b2 * (b6 * b6)>>12)>>11;
  x2 = (ac2 * b6)>>11;
  x3 = x1 + x2;
  b3 = (((((long)ac1)*4 + x3)<<3) + 2)>>2;
  
  // Calculate B4
  x1 = (ac3 * b6)>>13;
  x2 = (b1 * ((b6 * b6)>>12))>>16;
  x3 = ((x1 + x2) + 2)>>2;
  b4 = (ac4 * (unsigned long)(x3 + 32768))>>15;
  
  b7 = ((unsigned long)(up - b3) * (50000>>3));
  if (b7 < 0x80000000)
    p = (b7<<1)/b4;
  else
    p = (b7/b4)<<1;
    
  x1 = (p>>8) * (p>>8);
  x1 = (x1 * 3038)>>16;
  x2 = (-7357 * p)>>16;
  p += (x1 + x2 + 3791)>>4;
  
  return p;
}
