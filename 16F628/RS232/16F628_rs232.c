 /*********************************************
 *    dELAb - Deniz Elektronik Lab.           *
 *  PIC Geliþtirme Kartý için Örnek Program   *
 *                                            *
 *    PIC16F628 için RS232 KULLANIMI          *
 *                                            *
 *  - RS232 için JP3 Seçili Olsun             *
 *  - Terminal programý 9600 Baud ayarlý      *
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

