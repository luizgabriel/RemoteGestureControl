/* 
 * File:   gyro.h
 * Author: luizg
 *
 * Created on 9 de Dezembro de 2018, 14:08
 */

#ifndef ORIENTATION_H
#define	ORIENTATION_H

#include "mpu6050.h"

typedef struct {
    vec3f rot;
    vec3f gyro;
    vec3f accel;
} orientation_t;

void OrientationSystem_Init(orientation_t* orient);
void OrientationSystem_Update(orientation_t* orient);

#endif	/* ORIENTATION_H */

