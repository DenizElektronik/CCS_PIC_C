
/*********************************************

       dELAb - ADC �rnek Program

 RA2 ve RA3 Analog giri�lerinden okunan voltaj
 de�eri RS232 ile (19200 Buad) bilgisayara
 g�nderilir. TX pini RC7 dir.

*********************************************/


/* Mikrodenet�i: 16F876A */
#include "16F876A.h"

/* 16F877 i�erisinde 10 Bit ADC vard�r */
#device ADC=10

/* Konfig�rasyon Bitleri */
#fuses HS,NOWDT,NOPROTECT,NOLVP

/* 20 MHz Kristal */
#use delay(clock=20000000)

/* 19200 Baud RS-232 ��k���, TX: RC6   RX: RC7 */
#use rs232(baud=19200, xmit=PIN_C6, rcv=PIN_C7)


void main() {

   int i;
   float value,deger;

   setup_port_a( ALL_ANALOG );
   setup_adc( ADC_CLOCK_INTERNAL );
   set_adc_channel( 2 );

   do {
         set_adc_channel( 2 );  /* RA2 */
         value = Read_ADC();
         deger = ( value * 5 ) / 1024;
         printf("\n\rRA2: %f Volt\n\r",deger);

         set_adc_channel( 3 ); /* RA3 */
         value = Read_ADC();
         deger = ( value * 5 ) / 1024;
         printf("\n\rRA3: %f Volt\n\r",deger);
         delay_ms(100);
   } while (TRUE);
}
