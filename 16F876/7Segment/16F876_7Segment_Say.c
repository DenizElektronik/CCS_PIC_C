 /*********************************************
 *  dELAb - Deniz Elektronik Lab.             *
 *  PIC Geli�tirme Kart� i�in �rnek Program   *
 *                                            *
 * Bu �rnekte 0-9999 say�c� yap�p             *
 * 7 Segment �zerinde g�steriyoruz.           *
 * Y�zler hanesinde nokta belirmesini         *
 * sa�l�yoruz.                                *
 *                                            *
 * Programlama:                               *
 * Programlama yaparken LED ve 7Segment       *
 * DIPSwitch kapal� konumda olacak.           *
 * Hata al�rsan�z kristali s�k�p tekrarlay�n. *
 *********************************************/

#include "16F876A.h"        /* PIC16F876A Kullan�l�yor */
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
                    PORTA = 0x02; /* Y�zler */
                    Deger = number % 10;
                    number /= 10;
                   }
 
  if (Basamak==4)  {
                    PORTA = 0x01; /* Binler */
                    Deger = number;
                   }


      if (Basamak==3)          {

          PORTB = Digit[Deger] ^ 0x80; /* Y�zler basama��na Nokta ilave ediliyor */
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
