
/*********************************
   dELAb PIC Develeopment Board
   Binary Sayýcý Örnek Program
*********************************/

#include "16F876A.h"
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP
#use DELAY(clock=20000000)    // 20 MHz Kristal

void Main()
   {

   int i;                     // i tamsayý

   for (i=0 ; i<256 ; i++) {  // 0 ile 255 arasýnda say
       Output_B(i);           // PortB çýkýþýna gönder
       Output_C(~i);          // Invert yap ve PortC çýkýþýna gönder
       Delay_Ms(200);         // 200 ms bekle
       }
   }

