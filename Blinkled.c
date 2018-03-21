/* 
 * File:   Blinkled.c
 * Author: sofia
 *
 * Created on 19 de marzo de 2018, 08:57 AM
 */

#include <xc.h>
#include "configurationbits.h"

#define _XTAL_FREQ 8000000

/*
 * 
 */
int main() {
    TRISB0 = 0;
    while(1) {
        RB0 = 1;
        __delay_ms(1000);
        RB0 = 0;
        __delay_ms(1000);
    }
    return 0;
}
