/*
 * File:   ping pong prueba.c
 * Author: sofia
 *
 * Created on 11 de abril de 2018, 11:01 PM
 */

#include <xc.h>
#include "configuration_bits.h"

#define _XTAL_FREQ 8000000

void main() {
    TRISB=0x00;
    TRISA=0xFF;
    //TRISC=0x11111111;
    ANSELH=0x00;
    ANSEL=0x00;
    int i = 0;
    int d=0;
    RB0=0;
    RB1=1;
    RB2=0;
    RB3=0;
    RB4=0;
    RB5=0;
    RB6=0;
    RB7=0;
    while(1){
    if (d==0){
    if (RC0==1){//derechas a izquierda
        for(int i=2; i<=128; i=i*2){
            PORTB=i;
            __delay_ms(300);
            if (i==64){
                for (int o=0; o<750; o++){
                    for (int u=0; u<1000; u++){
                        if (RC1==1){
                            d=1;
                            break;
                        }
                        break;
                    }
                }
            }
            if(d==1){
                break;
            }
            if (i==128){
                RB7=1;
                __delay_ms(200);
                RB7=0;
                __delay_ms(200);
                RB7=1;
                __delay_ms(200);
                RB7=0;
                __delay_ms(200);
                RB7=1;
                __delay_ms(200);
                RB7=0;
                __delay_ms(200);
                PORTB=2;
                //break;
            }

        }

        //RB1=0;
       /* RB2=1;
        __delay_ms(300);
        RB2=0;
        __delay_ms(300);
        RB3=1;
        __delay_ms(300);
        RB3=0;
        __delay_ms(300);
        RB4=1;
        __delay_ms(300);
        RB4=0;
        __delay_ms(300);
        RB5=1;
        __delay_ms(300);
        RB5=0;
        __delay_ms(300);
        RB6=1;
        __delay_ms(300);
        RB6=0;
        __delay_ms(300);*/
    }
    }
    if (d==1){
        if (RC1==1){
       for (int i=64; i>=1; i=i/2){
         PORTB=i;
         __delay_ms(300);
         if (i==2){
             for (int o=0; o<750; o++){
                 for (int u=0; u<1000; u++){
                     if (RC0==1){
                         d=0;
                         break;
                     }
                     break;
                 }
             }
         }
        if (d==0){
             break;
        }
        if (i==1){
            RB0=1;
            __delay_ms(200);
            RB0=0;
            __delay_ms(200);
            RB0=1;
            __delay_ms(200);
            RB0=0;
            __delay_ms(200);
            RB0=1;
            __delay_ms(200);
            RB0=0;
            __delay_ms(200);
            PORTB=64;
            break;          
        }
       }
    }
    }
}
    return;
}