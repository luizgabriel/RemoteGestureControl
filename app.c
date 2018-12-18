#include "app.h"

volatile byte tmr0_counter;
volatile byte should_stop;

void App_Init()
{
    Bluetooth_Init();
    OrientSys_Init();
    
    should_stop = 1;
    tmr0_counter = -1;
    INTCONbits.GIE = 1;
    INTCONbits.GIEH = 1;
}

void App_Update()
{
    OrientSys_Update();
    GREEN_LED = OrientSys_Is(LEFT);
    WHITE_LED = OrientSys_Is(RIGHT);
    
    if (OrientSys_Is(RIGHT))
        Bluetooth_Send_Right();
    else if (OrientSys_Is(LEFT))
        Bluetooth_Send_Left();
    
    if ((OrientSys_Is(DOWN) || OrientSys_Is(UP)) && !INTCONbits.TMR0IE) {
        OpenTimer0(T0_PS_1_16 | T0_SOURCE_INT | T0_16BIT | TIMER_INT_ON);
        WriteTimer0(TIMER0_START);
        tmr0_counter = 0;
    } 
    
    if (OrientSys_Is(STABLE)) {
        tmr0_counter = -1;
        should_stop = 1;
        CloseTimer0();
        
        RED_LED = 0;
        YELLOW_LED = 0;
    }
}

void App_UpdateTimer0()
{
    if (tmr0_counter >= 0 && tmr0_counter < 6) {
        tmr0_counter++;
        
        if (should_stop)
            Bluetooth_Send_Stop();
        
        if (OrientSys_Is(UP) && should_stop) {
            RED_LED = ~RED_LED;
            YELLOW_LED = 0;
        } else if (OrientSys_Is(DOWN) && should_stop) {
            YELLOW_LED = ~YELLOW_LED;
            RED_LED = 0;
        } else {
            if (!OrientSys_Is(DOWN))
                YELLOW_LED = 0;
            
            if (!OrientSys_Is(UP))
                RED_LED = 0;
            
            tmr0_counter = -1;
            should_stop = 0;
            CloseTimer0();
        }
        
    } else if (tmr0_counter == 6) {
        tmr0_counter = -1;
        should_stop = 0;
        CloseTimer0();
        
        if (OrientSys_Is(UP)) {
            Bluetooth_Send_Go();
            RED_LED = 1;
        } else if (OrientSys_Is(DOWN)) {
            Bluetooth_Send_Back();
            YELLOW_LED = 1;
        } else {
            RED_LED = 0;
            YELLOW_LED = 0;
        }
    }
    
    WriteTimer0(TIMER0_START);
}