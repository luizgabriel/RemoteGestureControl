/* 
 * File:   comm.h
 * Author: luizg
 *
 * Created on 7 de Dezembro de 2018, 21:09
 */

#ifndef COMM_H
#define	COMM_H

#include "system.h"

#define OBJ_TURN_RIGHT 'R'
#define OBJ_TURN_LEFT 'L'
#define OBJ_STOP 'S'
#define OBJ_GO 'G'
#define OBJ_GO_BACK 'B'

void Comm_Init();

void Comm_Send(char command);

void Comm_WaitsOK();

#endif	/* COMM_H */

