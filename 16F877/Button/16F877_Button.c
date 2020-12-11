/*
�N AYARLAR:

1)    Tu� Tak�m� Jumper Ayar�n� (H-L SELECT)
      +5V'a (HIGH) Getirin
      Bu jumper hemen besleme giri�inin yukar�s�ndad�r

2)    Port Led grubu anahtarlar� ON konumunda olmal�
      Led grubunun sa��nda, �stte bulunan dip-switch
*/

#include "16F877A.h"
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use Delay(clock=20000000)
#use Fast_IO(A)
#use Fast_IO(B)
#byte PORTB=6


void main() {

/*
E�er port durumlar�n� a�a��daki gibi siz ayarlamak istiyorsan�z
#use Fast_IO(Port) gibi deklerasyon yapman�z gerekir.
Normalde aksi belirtilmedik�e CCS dili sizin komutlar�n�za 
g�re TRIS ayarlar�n� otomatik olarak yapmaktad�r.
*/
set_tris_a (0x01); 
set_tris_b (0x00); 
output_b(0x00); 

 While(1){

/*
A�a��daki komut ile PIN_B1'e ba�l� led s�rekli yan�p s�necektir.
Bu led, y�klenen program�n�z�n �al��t���n� g�sterir ve siz de emin olursunuz
*/
output_toggle(pin_b1);

/*
E�er A0 pin girdisi HIGH olursa B0 ��k��� HIGH olsun,
de�ilse B0 ��k��� LOW olacak
*/
if (input(pin_a0)) 
         output_high(pin_b0);
         else
         output_low(pin_b0); 

/*
Tu� tak�m� okumalar�nda biraz gecikmeye ihtiya� var
*/
Delay_Ms(100);

  }

 }
