#include "gyros.h"

void Gyros_Init()
{
    Gyros_Accel.x = 0;
    Gyros_Accel.y = 0;
    Gyros_Accel.z = 0;
    
    Gyros_Rot.phi = 0;
    Gyros_Rot.psi = 0;
    Gyros_Rot.theta = 0;
}

void Gyros_Update()
{
    vec3f a;
    Accel_Get(&a);
    
    Gyros_Accel.x = a.x;
    Gyros_Accel.y = a.y;
    Gyros_Accel.z = a.z;
    
    Gyros_UpdateRotation(&a);
}

void Gyros_UpdateRotation(vec3f* a)
{
    Gyros_Rot.theta = atan(a->x / sqrt(pow(a->y, 2) + pow(a->z, 2))) * RAD_2_EULER;
    Gyros_Rot.psi = atan(a->y / sqrt(pow(a->x, 2) + pow(a->z, 2))) * RAD_2_EULER;
    Gyros_Rot.phi = atan(a->z / sqrt(pow(a->x, 2) + pow(a->y, 2))) * RAD_2_EULER;
}