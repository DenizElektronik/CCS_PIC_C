
/*********************************************

       dELAb - ADC �rnek Program

 RA2 ve RA3 Analog giri�lerinden okunan voltaj
 LCD �zerinde G�sterilir
 
*********************************************/


/* Mikrodenet�i: 16F877A */
#include "16F877A.h"

/* 16F877 i�erisinde 10 Bit ADC vard�r */
#device ADC=10

/* Konfig�rasyon Bitleri */
#fuses HS,NOWDT,NOPROTECT,NOLVP

/* 20 MHz Kristal */
#use delay(clock=20000000)

#include "dELAb_LCD.c"

void main() {

   int i;
   float value,deger;
   char cX;

   setup_port_a( ALL_ANALOG );
   setup_adc( ADC_CLOCK_INTERNAL );

    LCD_Init();
    LCD_PutCmd ( CLEAR_DISP );

   do {
         set_adc_channel( 2 );  /* RA2 */
         value = Read_ADC();
         deger = ( value * 5 ) / 1024;
         LCD_SetPosition ( LINE_1 + 0 );
         printf ( LCD_PutChar,"RA2: %g V  ",deger);

         set_adc_channel( 3 ); /* RA3 */
         value = Read_ADC();
         deger = ( value * 5 ) / 1024;
         LCD_SetPosition ( LINE_2 + 0 );
         printf ( LCD_PutChar,"RA3: %g V  ",deger);

        delay_ms(100);

   } while (TRUE);
}
