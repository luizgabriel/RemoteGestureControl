#include "comm.h"

void Comm_Init()
{
    putsUSART((char*) "AT\r\n"); //Test Connection
    Comm_WaitsOK();
    putsUSART((char*) "AT+NAME=RmGestCtrl\r\n"); // Set device name
    Comm_WaitsOK();
    putsUSART((char*) "AT+ROLE=1\r\n"); // Set to master mode
    Comm_WaitsOK();
    putsUSART((char*) "AT+CMOD=1\r\n"); // Set connection mode to any address
    Comm_WaitsOK();
    
    //putsUSART("AT+CMOD=0\r\n"); // Set connection mode to fixed address
    //putsUSART("AT+BIND==123456abcde\r\n");
    //Comm_WaitsOK();
}

void Comm_Send(char command)
{
    char c[2];
    sprintf((char*) "%c0\r\n", (const char*) &command);
    putsUSART(c);
}

void Comm_WaitsOK()
{
    char buffer[2] = "";

    do {
        getsUSART(buffer, 2);
    } while (buffer[0] == 'O' && buffer[1] == 'K');
}
