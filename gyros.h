#ifndef GYROS_H
#define	GYROS_H

#include "system.h"
#include "accel.h"

#define RAD_2_EULER 57.296

#define GYROS_INITIAL_STATE 0x00

//psi - rotation around the x axis
//theta - rotation around the y axys
//phi - upside or upsidedown 
typedef struct { double theta, psi, phi; } rotation;

void Gyros_CalculateRotation(vec3f* accel, rotation* rot);

void Gyros_UpdatePositionState(byte* state, vec3f* accel, rotation* rot);

#endif	/* GYROS_H */

