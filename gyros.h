#ifndef GYROS_H
#define	GYROS_H

#include "system.h"
#include "accel.h"

#define RAD_2_EULER 57.296

//psi - rotation around the x axis
//theta - rotation around the y axys
//phi - upside or upsidedown 
typedef struct { double theta, psi, phi; } rotation;

rotation Gyros_Rot;
vec3f Gyros_Accel;

void Gyros_Init();
void Gyros_Update();
void Gyros_UpdateRotation(vec3f* accel);

#endif	/* GYROS_H */

