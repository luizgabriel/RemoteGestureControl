/* 
 * File:   comm.h
 * Author: luizg
 *
 * Created on 7 de Dezembro de 2018, 21:09
 */

#ifndef BLUETOOTH_H
#define	BLUETOOTH_H

#include "system.h"

void Bluetooth_Init();
void Bluetooth_Send(char* text);

void Bluetooth_Send_Go();
void Bluetooth_Send_Stop();
void Bluetooth_Send_Left();
void Bluetooth_Send_Right();
void Bluetooth_Send_Back();

#endif	/* BLUETOOTH_H */

