#include "system.h"

void interrupt high_priority System_HighPriorityInterrupt()
{
    //
}

void interrupt low_priority System_LowPriorityInterrupt()
{
    //
}

void System_Init()
{
    OSCCONbits.SCS = 0b11; //Internal Osccilator
    OSCCONbits.IRCF = 0b111; //16 MHz
    TRISDbits.RD0 = 0; //RD0 Output
    TRISDbits.RD1 = 0; //RD1 Output
    TRISDbits.RD2 = 0; //RD2 Output
    TRISDbits.RD3 = 0; //RD3 Output
    
    //Initialize USART
    CloseUSART();
    
    // spbrg = ( ( FOSC/BAUD ) / 64 ) -1 @Asynchronous @BRGH_Low
    // 5 = (16Mhz | 38400 Baud rate)
    OpenUSART(USART_TX_INT_OFF | USART_RX_INT_OFF | USART_ASYNCH_MODE 
              | USART_EIGHT_BIT | USART_CONT_RX | USART_BRGH_LOW, 5);
    baudUSART (BAUD_8_BIT_RATE | BAUD_AUTO_OFF);
    
    //Initialize I2C
    CloseI2C();
    OpenI2C(MASTER, SLEW_OFF);
    
    // ((Fosc/BitRate)/4)-1 
    SSPADD = 39; //100kHz Baud clock(39) @16MHz
                 //400kHz Baud clock(9) @16MHz
}
