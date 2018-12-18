#ifndef SYSTEM_H
#define	SYSTEM_H

#define _XTAL_FREQ 16000000
#define USE_OR_MASKS
#define AUSART_V1

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
#include <string.h>

// spbrg = ( ( FOSC/BAUD ) / 16 ) -1 @Asynchronous @BRGH_HIGH
typedef enum {
    USART_9600=103,
    USART_38400=25,
    USART_115200=7
} usart_baud_t;

typedef unsigned char byte;

void interrupt high_priority System_HighPriorityInterrupt();

void System_Init();

void System_OpenUSART(usart_baud_t baud);

#endif	/* SYSTEM_H */

