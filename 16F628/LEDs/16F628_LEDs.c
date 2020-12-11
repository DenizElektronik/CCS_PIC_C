
/*********************************
   dELAb PIC Develeopment Board
   Binary Sayýcý Örnek Program
*********************************/

#include "16F628A.h"
#use delay (Clock=4000000) /* 4 MHz */
#fuses INTRC,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOLVP,MCLR

void Main()
   {

   int i;                     // i tamsayý

   setup_comparator(NC_NC_NC_NC);

   for (i=0 ; i<256 ; i++) {  // 0 ile 255 arasýnda say
       Output_B(i);           // PortB çýkýþýna gönder
       Delay_Ms(200);         // 200 ms bekle
       }
   }

