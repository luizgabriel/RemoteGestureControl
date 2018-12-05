#include "accel.h"

void Accel_Init()
{
    byte name = Accel_ReadRegister(WHO_AM_I);
    while (name != 0x2A);

    Accel_StandBy();
    
    //Set up the full scale range to 2, 4, or 8g.
    byte fsr = GSCALE;
    if(fsr > 8) fsr = 8;
    fsr >>= 2;
    Accel_WriteRegister(XYZ_DATA_CFG, fsr);
    
    Accel_Active();
}

void Accel_StandBy()
{
    byte c = Accel_ReadRegister(CTRL_REG1);
    Accel_WriteRegister(CTRL_REG1, c & 0xFE); //Clear the active bit to go into standby
}

void Accel_Active()
{
    byte c = Accel_ReadRegister(CTRL_REG1);
    Accel_WriteRegister(CTRL_REG1, c | 0x01); //Set the active bit to begin detection
}

void Accel_Get(vec3f* out)
{
    char raw[6];
    float* f_out = (float*) &out;
    
    Accel_ReadRegisters(OUT_X_MSB, raw, 6);
    
    for(int i = 0; i < 3 ; i++)
    {
        int gCount = (raw[i*2] << 8) | raw[(i*2)+1]; 
        gCount >>= 4;

        // If the number is negative, we have to make it so manually (no 12-bit data type)
        if (raw[i*2] > 0x7F)
        {  
            gCount = ~gCount + 1;
            gCount *= -1;  // Transform into negative 2's complement #
        }

        f_out[i] = (float) gCount / ((1<<12)/(2*GSCALE)); 
    }
}

void Accel_WriteRegister(byte reg, byte value)
{
    EEByteWrite(MMA8452_ADDRESS, reg, value);
}

byte Accel_ReadRegister(byte reg)
{
    byte out = 0;
    EESequentialRead(MMA8452_ADDRESS, reg, &out, 1);
    return out;
}

void Accel_ReadRegisters(byte reg, byte* out, int length)
{
    EESequentialRead(MMA8452_ADDRESS, reg, out, length);
}
