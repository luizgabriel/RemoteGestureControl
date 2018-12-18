/* 
 * File:   gyro.h
 * Author: luizg
 *
 * Created on 9 de Dezembro de 2018, 14:08
 */

#ifndef ORIENTATION_H
#define	ORIENTATION_H

#include "mpu6050.h"

typedef enum {
    STABLE = 1,
    UP = 2,
    DOWN = 4,
    RIGHT = 8,
    LEFT = 16
} orientation_states_t;

typedef struct {
    vec3f rot;
    byte flags;
} orientation_t;

void OrientSys_Init();
void OrientSys_Update();
byte OrientSys_Is(orientation_states_t state);
void OrientSys_SetFlag(orientation_states_t state, byte value);

#endif	/* ORIENTATION_H */

