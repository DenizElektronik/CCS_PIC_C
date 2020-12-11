 /*********************************************
 *    dELAb - Deniz Elektronik Lab.           *
 *  PIC Geliþtirme Kartý için Örnek Program   *
 *                                            *
 *    7 Segment LED Display Kullanýmý         *
 *********************************************/


#include "16F628A.h"
#use delay (Clock=4000000) /* 4 MHz */
#fuses INTRC,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP,MCLR
#byte PORTA = 5
#byte PORTB = 6

// Segment Bilgileri:   0    1    2    3    4    5    6    7    8    9
byte const Digit[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void Main() {

 Byte Say, Basamak;

  setup_comparator(NC_NC_NC_NC); 
  set_tris_a(0x20);
  set_tris_b(0x00);
  port_b_pullups(true) ;

 while(1){
 for (Basamak=1;Basamak<5;Basamak++){

    if (Basamak==1) PORTA = 0x08; /* RA3 High */
    if (Basamak==2) PORTA = 0x04; /* RA2 High */
    if (Basamak==3) PORTA = 0x02; /* RA1 High */
    if (Basamak==4) PORTA = 0x01; /* RA0 High */

    for (Say=0;Say<10;Say++){
        PORTB= Digit[Say];
        Delay_Ms(300);

         }
      }
   }
}
