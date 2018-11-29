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
    ADCON1 |= 0x0F;
    TRISA = 0b11111101;
    ACTIVE_LED = 0;
    
    //Inititalize Libraries
    
    ACTIVE_LED = 1;
}