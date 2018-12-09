#include "mpu6050.h"

int MPU_Init()
{
    // Check MPU6050 Who Am I Register
    if (MPU_ReadRegister(MPU6050_REG_WHO_AM_I) != 0x68)
        return 0;
    
    // Set Clock Source
    MPU_SetClockSource(MPU6050_CLOCK_PLL_XGYRO);

    // Disable Sleep Mode
    MPU_SetSleepEnabled(0);

    return 1;
}

void MPU_SetClockSource(mpu6050_clockSource_t source)
{
    byte value;
    value = MPU_ReadRegister(MPU6050_REG_PWR_MGMT_1);
    value &= 0b11111000;
    value |= source;
    MPU_WriteRegister(MPU6050_REG_PWR_MGMT_1, value);
}

void MPU_SetSleepEnabled(byte state)
{
    MPU_WriteRegisterBit(MPU6050_REG_PWR_MGMT_1, 6, state);
}

void MPU_SetGyroOffsetX(int offset)
{
    MPU_WriteRegister16(MPU6050_REG_GYRO_XOFFS_H, offset);
}

void MPU_SetGyroOffsetY(int offset)
{
    MPU_WriteRegister16(MPU6050_REG_GYRO_YOFFS_H, offset);
}

void MPU_SetGyroOffsetZ(int offset)
{
    MPU_WriteRegister16(MPU6050_REG_GYRO_ZOFFS_H, offset);
}

void MPU_GetGyro(vec3* out)
{
    byte values[6];
	EESequentialRead(MPU6050_ADDRESS, MPU6050_REG_GYRO_XOUT_H, values, 6);

    out->x = values[0] << 8 | values[1];
    out->y = values[2] << 8 | values[3];
    out->z = values[4] << 8 | values[5];
}

//<editor-fold desc="I2C Helper Functions" defaultstate="collapsed">
byte MPU_ReadRegister(byte reg)
{
    return EERandomRead(MPU6050_ADDRESS, reg);
}

void MPU_WriteRegister(byte reg, byte value)
{
    EEByteWrite(MPU6050_ADDRESS, reg, value);
    EEAckPolling(MPU6050_ADDRESS);
}

int MPU_ReadRegister16(byte reg)
{
    byte values[2];
    EESequentialRead(MPU6050_ADDRESS, reg, values, 2);
    
    int result = values[0] << 8 | values[1];
    return result;
}

void MPU_WriteRegister16(byte reg, int value)
{
    byte values[2] = {(byte) value >> 8, (byte) value};
    EEPageWrite(MPU6050_ADDRESS, reg, values, 2);
    EEAckPolling(MPU6050_ADDRESS);
}

byte MPU_ReadRegisterBit(byte reg, byte pos)
{
    byte value = MPU_ReadRegister(reg);
    return ((value >> pos) & 1);
}

void MPU_WriteRegisterBit(byte reg, byte pos, byte state)
{
    byte value = MPU_ReadRegister(reg);
    if (state) {
        value |= (1 << pos);
    } else {
        value &= ~(1 << pos);
    }

    MPU_WriteRegister(reg, value);
}
//</editor-fold>
