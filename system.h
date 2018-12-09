#ifndef SYSTEM_H
#define	SYSTEM_H

#define _XTAL_FREQ 16000000
#define USE_OR_MASKS
#define WHITE_LED LATDbits.LATD3
#define YELLOW_LED LATDbits.LATD2
#define RED_LED LATDbits.LATD1
#define GREEN_LED LATDbits.LATD0

#include <xc.h> 
#include <i2c.h>
#include <usart.h>
#include <timers.h>
#include <math.h>
#include <stdio.h>

typedef unsigned char byte;

void interrupt high_priority System_HighPriorityInterrupt();

void interrupt low_priority System_LowPriorityInterrupt();

void System_Init();

#endif	/* SYSTEM_H */

