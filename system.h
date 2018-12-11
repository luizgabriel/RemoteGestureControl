#ifndef SYSTEM_H
#define	SYSTEM_H

#define _XTAL_FREQ 16000000
#define USE_OR_MASKS
#define WHITE_LED LATEbits.LATE1
#define YELLOW_LED LATDbits.LATD2
#define RED_LED LATBbits.LATB4
#define GREEN_LED LATDbits.LATD5

#include <xc.h> 
#include <i2c.h>
#include <usart.h>
#include <timers.h>
#include <math.h>
#include <stdio.h>

typedef unsigned char byte;

void System_Init();

float abs(float value);

#endif	/* SYSTEM_H */

