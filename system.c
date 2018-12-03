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
    TRISD = 0b11111110;
    TRISC = 0b00011000;
    ACTIVE_LED = 0;
    
    //Initialize USART
    CloseUSART();
    OpenUSART(USART_TX_INT_OFF | USART_RX_INT_OFF | USART_ASYNCH_MODE 
              | USART_EIGHT_BIT | USART_CONT_RX | USART_BRGH_LOW, 51);
    baudUSART (BAUD_8_BIT_RATE | BAUD_AUTO_OFF);
    
    //Initialize I2C
    CloseI2C();
    OpenI2C(MASTER, SLEW_OFF);
    SSPADD = 0x0A;
    
    ACTIVE_LED = 1;
}
