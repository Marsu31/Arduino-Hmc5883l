/*
* datasheet :
* https://aerocontent.honeywell.com/aero/common/documents/myaerospacecatalog-documents/Defense_Brochures-documents/HMC5883L_3-Axis_Digital_Compass_IC.pdf
*/


#ifndef HMC5883L_H
#define HMC5883L_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

// I2C address (datasheet p2)
#define HMC5883L_ADDRESS_READ  0x3D
#define HMC5883L_ADDRESS_WRITE 0x3C

// registers
#define HMC5883_REG_CRA       0x00 // (rw)
#define HMC5883_REG_CRB       0x01 // (rw)
#define HMC5883_REG_MR        0x02 // (rw)
#define HMC5883_REG_OUT_X_MSB 0x03
#define HMC5883_REG_OUT_X_LSB 0x04
#define HMC5883_REG_OUT_Z_MSB 0x05
#define HMC5883_REG_OUT_Z_LSB 0x06
#define HMC5883_REG_OUT_Y_MSB 0x07
#define HMC5883_REG_OUT_Y_LSB 0x08
#define HMC5883_REG_SR        0x09
#define HMC5883_REG_IRA       0x0A
#define HMC5883_REG_IRB       0x0B
#define HMC5883_REG_IRC       0x0C

// CRA6 to CRA5 - MA1 to MA0 (datasheet p12)
#define HMC5883L_SAMPLES_1 B00000000 // default
#define HMC5883L_SAMPLES_2 B00100000
#define HMC5883L_SAMPLES_4 B01000000
#define HMC5883L_SAMPLES_8 B01100000

// CRA4 to CRA2 - DO2 to DO0 (datasheet p12)
#define HMC5883L_OUTPUTRATE_0_75 B00000000
#define HMC5883L_OUTPUTRATE_1_5  B00000100
#define HMC5883L_OUTPUTRATE_3    B00001000
#define HMC5883L_OUTPUTRATE_7_5  B00001100
#define HMC5883L_OUTPUTRATE_15   B00010000 // default
#define HMC5883L_OUTPUTRATE_30   B00010100
#define HMC5883L_OUTPUTRATE_75   B00011000

// CRA1 to CRA0 - MS1 to MS0 (datasheet p12)
#define HMC5883L_MEASUREMENT_MODE_NORMAL B00000000 // default
#define HMC5883L_MEASUREMENT_MODE_BIAS_P B00000001
#define HMC5883L_MEASUREMENT_MODE_BIAS_N B00000010

// CRB7 to CRB5 - GN2 to GN0 (datasheet p13)
#define HMC5883L_RANGE_0_88 B00000000
#define HMC5883L_RANGE_1_3  B00100000 // default
#define HMC5883L_RANGE_1_9  B01000000
#define HMC5883L_RANGE_2_5  B01100000
#define HMC5883L_RANGE_4    B10000000
#define HMC5883L_RANGE_4_7  B10100000
#define HMC5883L_RANGE_5_6  B11000000
#define HMC5883L_RANGE_8_1  B11100000

// MR7 - HS0 (datasheet p14)
#define HMC5883L_I2C_SPEED_HIGH   B10000000
#define HMC5883L_I2C_SPEED_NORMAL B00000000 // default

// MR1 to MR0 - MD1 to MD0 (datasheet p14)
#define HMC5883L_OP_MODE_CONTINUOUS B00000000
#define HMC5883L_OP_MODE_SIMPLE     B00000001
#define HMC5883L_OP_MODE_IDLE       B00000010

// SR1 (datasheet p16)
#define HMC5883L_OUTPUT_LOCK B00000010

// SR0 (datasheet p16)
#define HMC5883L_OUTPUT_RDY B00000001

struct hmc5883l_vector
{
    float x;
    float y;
    float z;
};

class Hmc5883l
{
public:
    /** Default constructor */
    Hmc5883l();
    void begin();
    void setSamples();
    void setOutputrate();
    void setMeasurementMode();
    void setOperatingMode();
    void setRange();
protected:
private:
    hmc5883l_vector offset; //
    hmc5883l_vector measure; //
};

#endif // HMC5883L_H
