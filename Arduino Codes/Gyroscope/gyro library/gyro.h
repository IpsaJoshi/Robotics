  
/**************************************************************************
 *                                                                         *
 * GY-80 Driver for Arduino                                                *
 * By Sander Idelson                                                       *
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
#include <Wire.h>


#ifndef GY80_h
#define GY80_h


// Define L3G4200 registers
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define L3G4200D_DATAX0 0x28
#define L3G4200D_DATAX1 0x29
#define L3G4200D_DATAY0 0x2A
#define L3G4200D_DATAY1 0x2B
#define L3G4200D_DATAZ0 0x2C
#define L3G4200D_DATAZ1 0x2D

// Define ADXL345 registers
#define ADXL345_POWER_CTL 0x2D
#define ADXL345_DATAX0 0x32
#define ADXL345_DATAX1 0x33
#define ADXL345_DATAY0 0x34
#define ADXL345_DATAY1 0x35
#define ADXL345_DATAZ0 0x36
#define ADXL345_DATAZ1 0x37

// Define HMC5883 registers
#define HMC5883_SAMPLERATE_CTL 0x00
#define HMC5883_MODE_CTL 0x02
#define HMC5883_DATAX0 0x03
#define HMC5883_DATAX1 0x04
#define HMC5883_DATAY0 0x05
#define HMC5883_DATAY1 0x06
#define HMC5883_DATAZ0 0x07
#define HMC5883_DATAZ1 0x08

// Define BMP085 registers
#define BMP085_START_CTL 0xF4
#define BMP085_DATAT0 0xF6
#define BMP085_DATAT1 0xF7
#define BMP085_DATAT2 0xF8
class GY80
{
	int ac1;
  	int ac2;
  	int ac3;
  	int ac4;
  	int ac5;
  	int ac6;
  	int b1;
  	int b2;
  	int b5;
  	int mb;
  	int mc;
  	int md;

public:

	GY80();
	void writeRegister( int deviceAddress, byte address, byte val );
	int readRegister( int deviceAddress, byte address );

	void setupGyro( int scale );
	void setupAcc( void );
	void setupMag( void );
	void setupTemp( void );
	void setupPress( void );
	void getGyro( int *x, int *y, int *z );
	void getAcc( int *x , int *y, int *z );
	void getMag( int *x , int *y, int *z );
	void getTemp( int *t );
	long convertToTemp( int t );
	void getPress( int *p );
	long convertToPress( int up );
};


#endif
