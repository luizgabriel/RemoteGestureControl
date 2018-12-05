/* 
 * File:   gyros.h
 * Author: luizg
 *
 * Created on 3 de Dezembro de 2018, 20:03
 */

#ifndef GYROS_H
#define	GYROS_H

#include "system.h"
#include "accel.h"

typedef struct { double theta, phi; } angle;

static angle Gyros_Angle;
static vec3f Gyros_LastAccel;
static vec3f Gyros_Vel;

void Gyros_Init();

void Gyros_Update(float dt);

#endif	/* GYROS_H */

