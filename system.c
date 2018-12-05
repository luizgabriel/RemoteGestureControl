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
    TRISCbits.RC0 = 0; //RC0 Output
    ACTIVE_LED = 0;
    
    //Initialize USART
    CloseUSART();
    OpenUSART(USART_TX_INT_OFF | USART_RX_INT_OFF | USART_ASYNCH_MODE 
              | USART_EIGHT_BIT | USART_CONT_RX | USART_BRGH_LOW, 51);
    baudUSART (BAUD_8_BIT_RATE | BAUD_AUTO_OFF);
    
    //Initialize I2C
    CloseI2C();
    OpenI2C(MASTER, SLEW_OFF);
    
    // ((Fosc/BitRate)/4)-1 
    SSPADD = 39; //100kHz Baud clock(39) @16MHz
                //400kHz Baud clock(9) @16MHz
    
    ACTIVE_LED = 1;
}
