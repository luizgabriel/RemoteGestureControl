#include "orientation.h"

void OrientationSystem_Init(orientation_t* orient)
{   
    int s, i;
    do {
        s = MPU_Init(MPU6050_RANGE_2G, MPU6050_SCALE_2000DPS);
        WHITE_LED = ~WHITE_LED;
        for (i = 0; i < 20; i++)
            __delay_ms(10);
    } while (!s);
    
    //Reset Rotation
    orient->rot.x = 0;
    orient->rot.y = 0;
    orient->rot.z = 0;
}

void OrientationSystem_Update(orientation_t* o)
{
    MPU_GetGyro(&o->gyro);
    MPU_GetAccel(&o->accel);
    
    o->rot.x = atan(o->accel.x / sqrt(pow(o->accel.y, 2) + pow(o->accel.z, 2))) * 57.2958f;
    o->rot.y = atan(o->accel.y / sqrt(pow(o->accel.x, 2) + pow(o->accel.z, 2))) * 57.2958f;
    o->rot.z = atan(o->accel.z / sqrt(pow(o->accel.y, 2) + pow(o->accel.x, 2))) * 57.2958f;
}

