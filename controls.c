#include "controls.h"

void Controls_Update()
{
    if (Gyros_Rot.phi > 70 || Gyros_Rot.phi < -70)
        ACTIVE_LED = 1;
    else
        ACTIVE_LED = 0;
}