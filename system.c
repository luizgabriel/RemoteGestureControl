#include "system.h"

void System_Init()
{
    OSCCONbits.SCS = 0b11; //Internal Osccilator
    OSCCONbits.IRCF = 0b111; //16 MHz
    ANSELbits.ANS6 = 0; //Enables RE1 as Digital
    TRISDbits.RD2 = 0;
    TRISEbits.RE1 = 0;
    TRISBbits.RB4 = 0;
    TRISDbits.RD5 = 0;
    WHITE_LED = 0;
    RED_LED = 0;
    GREEN_LED = 0;
    YELLOW_LED = 0;
    
    //Initialize I2C
    CloseI2C();
    OpenI2C(MASTER, SLEW_OFF);
    
    // ((Fosc/BitRate)/4)-1 
    SSPADD = 39; //100kHz Baud clock(39) @16MHz
                 //400kHz Baud clock(9) @16MHz
    
    for (int i = 0; i < 10; i++)
        __delay_ms(10);
}

void System_OpenUSART(usart_baud_t baud)
{
    CloseUSART();
    
    // spbrg = ( ( FOSC/BAUD ) / 64 ) -1 @Asynchronous @BRGH_Low
    OpenUSART(USART_TX_INT_OFF | USART_RX_INT_OFF | USART_ASYNCH_MODE | USART_EIGHT_BIT | USART_CONT_RX | USART_BRGH_HIGH, baud);
    baudUSART(BAUD_8_BIT_RATE | BAUD_AUTO_OFF);
    
    for (int i = 0; i < 10; i++)
        __delay_ms(10);
}