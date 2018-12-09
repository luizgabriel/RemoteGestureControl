#include "gyros.h"

void Gyros_CalculateRotation(vec3f* a, rotation* rot)
{
    rot->theta = atan(a->x / sqrt(pow(a->y, 2) + pow(a->z, 2))) * RAD_2_EULER;
    rot->psi = atan(a->y / sqrt(pow(a->x, 2) + pow(a->z, 2))) * RAD_2_EULER;
    rot->phi = atan(a->z / sqrt(pow(a->x, 2) + pow(a->y, 2))) * RAD_2_EULER;
}

byte Gyros_GetState(byte lastState, vec3f* accel, rotation* rot)
{
    byte stable = rot->phi > 70;
    byte right = rot->theta > 60;
    byte left = rot->theta < -60;
    byte up = rot->psi < -60;
    byte down = rot->psi > 60;
    byte wasStable = lastState == GYROS_STABLE;
    
    if (right && (wasStable || lastState == GYROS_RIGHT))
        return GYROS_RIGHT;
    else if (left && (wasStable || lastState == GYROS_LEFT))
        return GYROS_LEFT;
    else if (up && !right && !left && (wasStable || lastState == GYROS_UP))
        return GYROS_UP;
    else if (down && (wasStable || lastState == GYROS_DOWN))
        return GYROS_DOWN;
    else if (stable)
        return GYROS_STABLE;
    else
        return lastState;
}