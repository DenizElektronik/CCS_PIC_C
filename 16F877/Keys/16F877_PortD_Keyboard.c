/*

Tuþ takýmý Jumper (JUMP1)
+5V (High) Konumunda Olacak

RD Portunda Basýlan Tuþlar
LCD 'de gösterilecektir

*/

#include "16F877A.h"
#fuses HS,NOWDT,PUT,NOPROTECT,NOLVP,BROWNOUT
#use Delay(Clock=20000000)

#include "dELAb_LCD.c"

#use Fast_IO ( D )

#byte PORTB = 6
#byte PORTD = 8

#define Bekle 100

void main ( void )
    {
    Int BasilanTus;

    Set_Tris_D ( 0xFF );

    LCD_Init();
    LCD_PutCmd ( CLEAR_DISP );
    LCD_SetPosition ( LINE_1 + 0 );
    printf ( LCD_PutChar, " PortD Tusa Bas ");

  While(1){

  if (Bit_Test(PORTD,0)==1) {BasilanTus=1;}
  if (Bit_Test(PORTD,1)==1) {BasilanTus=2;}
  if (Bit_Test(PORTD,2)==1) {BasilanTus=3;}
  if (Bit_Test(PORTD,3)==1) {BasilanTus=4;}
  if (Bit_Test(PORTD,4)==1) {BasilanTus=5;}
  if (Bit_Test(PORTD,5)==1) {BasilanTus=6;}
  if (Bit_Test(PORTD,6)==1) {BasilanTus=7;}
  if (Bit_Test(PORTD,7)==1) {BasilanTus=8;}


  if (BasilanTus!=0)
         {
         LCD_SetPosition ( LINE_2 + 0 );
         Printf ( LCD_PutChar, "Tus: RD%U   ", BasilanTus-1 );
         }
         else
         {
         LCD_SetPosition ( LINE_2 + 0 );
         Printf ( LCD_PutChar, "Tus: ---   ");
         }         

  BasilanTus=0;
  PORTB = 0x00;
  PORTD = 0x00;
  Delay_Ms(Bekle);

   }

 }
