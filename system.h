#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h> 
#include <i2c.h>
#include <usart.h>
#include <timers.h>

#define _XTAL_FREQ 48000000
#define ACTIVE_LED LATAbits.LATA1

void interrupt high_priority System_HighPriorityInterrupt();

void interrupt low_priority System_LowPriorityInterrupt();

void System_Init();

#endif	/* SYSTEM_H */

