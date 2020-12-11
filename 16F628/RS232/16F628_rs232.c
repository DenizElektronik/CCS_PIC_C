 /*********************************************
 *    dELAb - Deniz Elektronik Lab.           *
 *  PIC Geli�tirme Kart� i�in �rnek Program   *
 *                                            *
 *    PIC16F628 i�in RS232 KULLANIMI          *
 *                                            *
 *  - RS232 i�in JP3 Se�ili Olsun             *
 *  - Terminal program� 9600 Baud ayarl�      *
 *    olsun
 *********************************************/

#include "16F628A.h"
#use delay (Clock=4000000) /* 4 MHz */
#fuses INTRC,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP,MCLR
#use rs232(baud=9600, xmit=PIN_B2, rcv=PIN_B1)

void Main() {

  setup_comparator(NC_NC_NC_NC);

 while(1){

      printf("\n\rdELAb PIC Development Board");
      delay_ms(100);

      }
  }

