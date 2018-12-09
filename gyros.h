#ifndef GYROS_H
#define	GYROS_H

#include "system.h"
#include "accel.h"

#define RAD_2_EULER 57.296

#define GYROS_DROP      0xFD
#define GYROS_UNKNOWN   0xFF
#define GYROS_STABLE    0
#define GYROS_RIGHT     1
#define GYROS_LEFT      2
#define GYROS_UP        3
#define GYROS_DOWN      4

//psi - rotation around the x axis
//theta - rotation around the y axys
//phi - upside or upsidedown 
typedef struct { double theta, psi, phi; } rotation;

void Gyros_CalculateRotation(vec3f* accel, rotation* rot);

byte Gyros_GetState(byte lastState, vec3f* accel, rotation* rot);

#endif	/* GYROS_H */

