#include <xc.h>
#include "system.h"

char hello[] = "Hello, world! <PL>\n\r";

void main() {
    System_Init();
    
    while (1) {
        while(BusyUSART());
        putsUSART(hello);
    }
}
