/* 
 * File:   app.h
 * Author: luizg
 *
 * Created on 14 de Dezembro de 2018, 10:59
 */

#ifndef APP_H
#define	APP_H

#include "system.h"
#include "orientation.h"
#include "bluetooth.h"
#define TIMER0_START 0x33

void App_Init();
void App_Update();
void App_UpdateTimer0();

#endif	/* APP_H */

