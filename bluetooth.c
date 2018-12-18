#include "bluetooth.h"

void Bluetooth_Init()
{
    System_OpenUSART(USART_38400);
    Bluetooth_Send((char*) "AT+BAUD=4\r\n"); //Set baud 9600
    Bluetooth_Send((char*) "AT+NAME=RemoteGestureControl\r\n"); // Set device name
    Bluetooth_Send((char*) "AT+ROLE=0\r\n"); // Set to master mode
    Bluetooth_Send((char*) "AT+CMOD=1\r\n"); // Set connection mode to any address
    Bluetooth_Send((char*) "AT+PIN=5555\r\n"); // Set connection mode to any address
    System_OpenUSART(USART_9600);
}

void Bluetooth_Send(char* text)
{
    putsUSART(text);
    
    int i;
    for (i = 0; i < 10; i++) {
        __delay_us(50);
    }
}

void Bluetooth_Send_Go()
{
    Bluetooth_Send((char*) "CAR+GO\r\n");
}

void Bluetooth_Send_Stop()
{
    Bluetooth_Send((char*) "CAR+STOP\r\n");
}

void Bluetooth_Send_Left()
{
    Bluetooth_Send((char*) "CAR+LEFT\r\n");
}

void Bluetooth_Send_Right()
{
    Bluetooth_Send((char*) "CAR+RIGHT\r\n");
}

void Bluetooth_Send_Back()
{
    Bluetooth_Send((char*) "CAR+BACK\r\n");
}
