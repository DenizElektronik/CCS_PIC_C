
/*

Tuþ Takýmý Jumper Ayarýný (JUMP1)
GND'ye (Low) Getirin

RS232 Tx Jumper Ayarýný (JP4)
RC6 Seçin

*/

#include "16F876A.h"
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use Delay(clock=20000000)
#use Rs232(Baud=19200, Xmit = PIN_C6)
#use Fast_IO(B)
#byte PORTB=6

#define Bekle 400

void main() {

  Int BasilanTus;

  Port_B_PullUps(TRUE);

  Output_B(0xFF);

  While(1){

  if (Bit_Test(PORTB,0)==0) {BasilanTus=1;}
  if (Bit_Test(PORTB,1)==0) {BasilanTus=2;}
  if (Bit_Test(PORTB,2)==0) {BasilanTus=3;}
  if (Bit_Test(PORTB,3)==0) {BasilanTus=4;}
  if (Bit_Test(PORTB,4)==0) {BasilanTus=5;}
  if (Bit_Test(PORTB,5)==0) {BasilanTus=6;}
  if (Bit_Test(PORTB,6)==0) {BasilanTus=7;}
  if (Bit_Test(PORTB,7)==0) {BasilanTus=8;}

  if (BasilanTus!=0) Printf ("%U",BasilanTus);
  BasilanTus=0;
  Delay_Ms(Bekle);

  }

 }
