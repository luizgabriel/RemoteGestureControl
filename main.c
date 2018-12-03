#include <xc.h>
#include "system.h"
#include "accel.h"

char hello[] = "Hello, world! <PL>\n\r";

void main() {
    System_Init();
    
    ACTIVE_LED = 0;
    Accel_Init();
    ACTIVE_LED = 1;
    
    while (1) {
       ACTIVE_LED = ~ACTIVE_LED;
       for (int i = 0; i < 100; i++) __delay_ms(10);
    }
}
