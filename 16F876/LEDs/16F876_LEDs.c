
/*********************************
   dELAb PIC Develeopment Board
   Binary Say�c� �rnek Program
*********************************/

#include "16F876A.h"
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP
#use DELAY(clock=20000000)    // 20 MHz Kristal

void Main()
   {

   int i;                     // i tamsay�

   for (i=0 ; i<256 ; i++) {  // 0 ile 255 aras�nda say
       Output_B(i);           // PortB ��k���na g�nder
       Output_C(~i);          // Invert yap ve PortC ��k���na g�nder
       Delay_Ms(200);         // 200 ms bekle
       }
   }

