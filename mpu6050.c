#include "mpu6050.h"

int MPU_Init(mpu6050_range_t range, mpu6050_dps_t scale)
{
    // Check MPU6050 Who Am I Register
    if (MPU_ReadRegister(MPU6050_REG_WHO_AM_I) != 0x68)
        return 0;
    
    MPU_SetClockSource(MPU6050_CLOCK_PLL_XGYRO);
    MPU_SetScale(range);
    MPU_SetRange(scale);
    
    // Disable Sleep Mode
    MPU_SetSleepEnabled(0);

    return 1;
}

void MPU_SetScale(mpu6050_dps_t scale)
{
    byte value;
    
    switch (scale)
    {
        case MPU6050_SCALE_250DPS:
            MPU.dpsPerDigit = .007633f;
            break;
        case MPU6050_SCALE_500DPS:
            MPU.dpsPerDigit = .015267f;
            break;
        case MPU6050_SCALE_1000DPS:
            MPU.dpsPerDigit = .030487f;
            break;
        case MPU6050_SCALE_2000DPS:
            MPU.dpsPerDigit = .060975f;
            break;
        default:
            break;
    }

    value = MPU_ReadRegister(MPU6050_REG_GYRO_CONFIG);
    value &= 0b11100111;
    value |= (scale << 3);
    MPU_WriteRegister(MPU6050_REG_GYRO_CONFIG, value);
}

void MPU_SetRange(mpu6050_range_t range)
{
    switch (range)
    {
        case MPU6050_RANGE_2G:
            MPU.rangePerDigit = .000061f;
            break;
        case MPU6050_RANGE_4G:
            MPU.rangePerDigit = .000122f;
            break;
        case MPU6050_RANGE_8G:
            MPU.rangePerDigit = .000244f;
            break;
        case MPU6050_RANGE_16G:
            MPU.rangePerDigit = .0004882f;
            break;
        default:
            break;
    }
    
    byte value = MPU_ReadRegister(MPU6050_REG_ACCEL_CONFIG);
    value &= 0b11100111;
    value |= (range << 3);
    MPU_WriteRegister(MPU6050_REG_ACCEL_CONFIG, value);
}

void MPU_SetClockSource(mpu6050_clockSource_t source)
{
    byte value = MPU_ReadRegister(MPU6050_REG_PWR_MGMT_1);
    value &= 0b11111000;
    value |= source;
    MPU_WriteRegister(MPU6050_REG_PWR_MGMT_1, value);
}

void MPU_SetSleepEnabled(byte state)
{
    MPU_WriteRegisterBit(MPU6050_REG_PWR_MGMT_1, 6, state);
}

void MPU_GetGyro(vec3f* out)
{
    byte raw[6];
	EESequentialRead(MPU6050_ADDRESS, MPU6050_REG_GYRO_XOUT_H, raw, 6);
    
    float* f_out = (float*) out;
    for(int i = 0; i < 3; i++)
    {
        int dps = ((raw[i*2] << 8) | raw[(i*2)+1]);
        f_out[i] = dps * MPU.dpsPerDigit;
    }
}

void MPU_GetAccel(vec3f* out)
{
    byte raw[6];
	EESequentialRead(MPU6050_ADDRESS, MPU6050_REG_ACCEL_XOUT_H, raw, 6);
    
    float* f_out = (float*) out;
    for(int i = 0; i < 3; i++)
    {
        int g = ((raw[i*2] << 8) | raw[(i*2)+1]);
        f_out[i] = g * MPU.rangePerDigit;
    }
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
