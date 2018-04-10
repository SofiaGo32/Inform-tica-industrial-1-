/* 
 * File:   PWMLed.c
 * Author: Manuel
 *
 * Created on 8 de octubre de 2017, 08:35 PM
 */

#define _XTAL_FREQ 20000000
#define TMR2PRESCALE 4

#include <xc.h>
#include "cinfiguration_bits.h"

long PWM_freq = 5000;

PWM_Initialize()
{
  PR2 = (_XTAL_FREQ/(PWM_freq*4*TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
    CCP1M3 = 1; CCP1M2 = 1;  //Configure the CCP1 module 
    T2CKPS0 = 1;T2CKPS1 = 0; TMR2ON = 1; //Configure the Timer module
    TRISC2 = 0; // make port pin on C as output
}

PWM_Duty(unsigned int duty)
{
      if(duty<1023)
  {

    duty = ((float)duty/1023)*(_XTAL_FREQ/(PWM_freq*TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    DC1B1 = duty & 2; //Store the 1st bit
    DC1B0 = duty & 1; //Store the 0th bit
    CCPR1L = duty>>2;// Store the remining 8 bit
  }
}

void ADC_Initialize()
{
  ADCON0 = 0b10000001; //ADC ON and Fosc/32 is selected
  ADCON1 = 0b10000000; // Internal reference voltage is selected
}
unsigned int ADC_Read(unsigned char channel)
{
  ADCON0 &= 0x11000011; //Clearing the Channel Selection Bits
  ADCON0 |= channel<<2; //Setting the required Bits
  __delay_ms(2); //Acquisition time to charge hold capacitor
  ADCON0bits.GO = 1;
  //GO_nDONE = 1; //Initializes A/D Conversion
  while(ADCON0bits.GO); //Wait for A/D Conversion to complete
  return ((ADRESH<<8)+ADRESL); //Returns Result
}

void main()
{
    int adc_value=0;
  TRISC = 0x00; //PORTC as output
  TRISA = 0xFF; //PORTA as input
  TRISD = 0x00;
  ADC_Initialize(); //Initializes ADC Module
  PWM_Initialize();  //This sets the PWM frequency of PWM1

  do
  {
    PWM_Duty(adc_value);
    adc_value = ADC_Read(4); //Reading Analog Channel 4 
    __delay_ms(50); 
      
  }while(1); //Infinite Loop
  
}