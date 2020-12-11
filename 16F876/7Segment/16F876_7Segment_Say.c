 /*********************************************
 *  dELAb - Deniz Elektronik Lab.             *
 *  PIC Geliþtirme Kartý için Örnek Program   *
 *                                            *
 * Bu örnekte 0-9999 sayýcý yapýp             *
 * 7 Segment üzerinde gösteriyoruz.           *
 * Yüzler hanesinde nokta belirmesini         *
 * saðlýyoruz.                                *
 *                                            *
 * Programlama:                               *
 * Programlama yaparken LED ve 7Segment       *
 * DIPSwitch kapalý konumda olacak.           *
 * Hata alýrsanýz kristali söküp tekrarlayýn. *
 *********************************************/

#include "16F876A.h"        /* PIC16F876A Kullanýlýyor */
#use delay (Clock=20000000) /* 20 MHz Kristal */
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP
#byte PORTA = 5 /* PORTA Adresi */
#byte PORTB = 6 /* PORTB Adresi */

// Segment Bilgileri:   0    1    2    3    4    5    6    7    8    9  Derece
byte const Digit[11]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x63};
int Deger,Basamak;
long number,Say;

void Main() {

 set_tris_a(0b11110000);
 set_tris_b(0b00000000);

 while(1){

 for (Say=1;Say<9999;Say++){
 
 number = Say;
 
 for (Basamak=1;Basamak<5;Basamak++){

  if (Basamak==1)  {
                    PORTA = 0x08; /* Birler */
                    Deger = number % 10;
                    number /= 10;
                   }

  if (Basamak==2)  {
                    PORTA = 0x04; /* Onlar */
                    Deger = number % 10;
                    number /= 10;
                   }

  if (Basamak==3)  {
                    PORTA = 0x02; /* Yüzler */
                    Deger = number % 10;
                    number /= 10;
                   }
 
  if (Basamak==4)  {
                    PORTA = 0x01; /* Binler */
                    Deger = number;
                   }


      if (Basamak==3)          {

          PORTB = Digit[Deger] ^ 0x80; /* Yüzler basamaðýna Nokta ilave ediliyor */
          }
          else
          {
          PORTB = Digit[Deger];
          }

          Delay_Ms(6);
         
         }

      }

   }

}
