/* 
 * File:   accel.h
 * Author: luizg
 *
 * Created on 2 de Dezembro de 2018, 15:39
 */

#ifndef ACCEL_H
#define	ACCEL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "system.h"
    
#define MMA8452_ADDRESS 0x1D  // 0x1D if SA0 is high, 0x1C if low

//Define a few of the registers that we will be accessing on the MMA8452
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG  0x0E
#define WHO_AM_I   0x0D
#define CTRL_REG1  0x2A

#define GSCALE 2 // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.
    
typedef struct { float x, y, z; } vec3f;

int Accel_Init();

void Accel_StandBy();

void Accel_Active();

void Accel_Get(vec3f* out);

void Accel_WriteRegister(byte reg, byte data);

byte Accel_ReadRegister(byte reg);

void Accel_ReadRegisters(byte reg, byte* out, int length);

#ifdef	__cplusplus
}
#endif

#endif	/* ACCEL_H */

