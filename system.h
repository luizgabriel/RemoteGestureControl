#ifndef SYSTEM_H
#define	SYSTEM_H

#define _XTAL_FREQ 8000000
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
#define USE_OR_MASKS
#define ACTIVE_LED LATDbits.LATD0

#include <xc.h> 
#include <p18cxxx.h>
#include <i2c.h>
#include <usart.h>
#include <timers.h>

void interrupt high_priority System_HighPriorityInterrupt();

void interrupt low_priority System_LowPriorityInterrupt();

void System_Init();

#endif	/* SYSTEM_H */

