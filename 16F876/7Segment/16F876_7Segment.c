 /*********************************************
 *  dELAb - Deniz Elektronik Lab.             *
 *  PIC Geliþtirme Kartý için Örnek Program   *
 *                                            *
 *    7 Segment LED Display Kullanýmý         *
 *********************************************/


#include "16F876A.h"        /* PIC16F876A Kullanýlýyor */
#use delay (Clock=20000000) /* 20 MHz Kristal */
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP
#byte PORTA = 5 /* PORTA Adresi */
#byte PORTB = 6 /* PORTB Adresi */

// Segment Bilgileri:   0    1    2    3    4    5    6    7    8    9
byte const Digit[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void Main() {

   Byte Say, Basamak;

 set_tris_a(0b11110000);
 set_tris_b(0b00000000);

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
