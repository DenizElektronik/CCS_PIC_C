/*
Tuþ Takýmý Jumper Ayarýný (JUMP1)
GND'ye (Low) Getirin

DURUM:

PortA.1 butonuna basýldýðýnda
PortB.5 'e baðlý LED ýþýldayacaktýr.

*/

#include "16F628A.h"
#fuses INTRC
#byte PORTA = 0x05
#byte PORTB = 0x06

void main() {


/*		CLRF PORTB 
		BSF STATUS,5 
		CLRF TRISB 
		MOVLW H'FF' 
		MOVWF TRISA 
		BCF STATUS,5   */

   setup_comparator(NC_NC_NC_NC);  // Analog Kapalý

   Set_Tris_A(0b00001111);
   Set_Tris_B(0b00000000);
   Output_A(0b00000010); 
   Output_B(0b00000000); 


/*  TEST_PORTA 
	     	BTFSC PORTA,1 
   		GOTO TEST_PORTA 
	     	BSF PORTB,5   */

while (1){

if (Bit_Test(PORTA,1)==0) {
         Output_B(0b00100000);
         }
         else 
         {
         Output_B(0b00000000);
         }


    }
}
 
