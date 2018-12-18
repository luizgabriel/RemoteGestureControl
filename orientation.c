#include "orientation.h"

orientation_t orient;

void OrientSys_Init()
{   
    int s, i;
    do {
        s = MPU_Init(MPU6050_RANGE_2G, MPU6050_SCALE_2000DPS);
        WHITE_LED = ~WHITE_LED;
        for (i = 0; i < 20; i++)
            __delay_ms(10);
    } while (!s);
    WHITE_LED = 0;
    
    //Reset Rotation
    orient.rot.x = 0;
    orient.rot.y = 0;
    orient.rot.z = 0;
    orient.flags = 0;
}

void OrientSys_Update()
{
    vec3f gyro, accel;
    MPU_GetGyro(&gyro);
    MPU_GetAccel(&accel);
    
    orient.rot.x = atan(accel.x / sqrt(pow(accel.y, 2) + pow(accel.z, 2))) * 57.2958f;
    orient.rot.y = atan(accel.y / sqrt(pow(accel.x, 2) + pow(accel.z, 2))) * 57.2958f;
    orient.rot.z = atan(accel.z / sqrt(pow(accel.y, 2) + pow(accel.x, 2))) * 57.2958f;
    
    OrientSys_SetFlag(UP, orient.rot.y < -40);
    OrientSys_SetFlag(DOWN, orient.rot.y > 40);
    OrientSys_SetFlag(LEFT, orient.rot.x < -40);
    OrientSys_SetFlag(RIGHT, orient.rot.x > 40);
    OrientSys_SetFlag(STABLE, !OrientSys_Is(UP) && !OrientSys_Is(DOWN) && !OrientSys_Is(LEFT) && !OrientSys_Is(RIGHT));
}

byte OrientSys_Is(orientation_states_t state)
{
    return (orient.flags & state) != 0;
}

void OrientSys_SetFlag(orientation_states_t state, byte value)
{
    if (value) {
        orient.flags |= state;
    } else {
        orient.flags &= ~(state);
    }
}

