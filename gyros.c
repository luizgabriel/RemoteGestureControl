#include "gyros.h"

void Gyros_CalculateRotation(vec3f* a, rotation* rot)
{
    rot->theta = atan(a->x / sqrt(pow(a->y, 2) + pow(a->z, 2))) * RAD_2_EULER;
    rot->psi = atan(a->y / sqrt(pow(a->x, 2) + pow(a->z, 2))) * RAD_2_EULER;
    rot->phi = atan(a->z / sqrt(pow(a->x, 2) + pow(a->y, 2))) * RAD_2_EULER;
}

void Gyros_UpdatePositionState(byte* state, vec3f* accel, rotation* rot)
{
    // TODO: Interpret accel and rot to a State Machine and update the previous state
    
    //Test code
    if (rot->theta > 70 || rot->theta < -70 || rot->psi > 70 || rot->psi < -70)
        ACTIVE_LED = 1;
    else
        ACTIVE_LED = 0;
}