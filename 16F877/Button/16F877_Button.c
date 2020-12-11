/*
ÖN AYARLAR:

1)    Tuþ Takýmý Jumper Ayarýný (H-L SELECT)
      +5V'a (HIGH) Getirin
      Bu jumper hemen besleme giriþinin yukarýsýndadýr

2)    Port Led grubu anahtarlarý ON konumunda olmalý
      Led grubunun saðýnda, üstte bulunan dip-switch
*/

#include "16F877A.h"
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use Delay(clock=20000000)
#use Fast_IO(A)
#use Fast_IO(B)
#byte PORTB=6


void main() {

/*
Eðer port durumlarýný aþaðýdaki gibi siz ayarlamak istiyorsanýz
#use Fast_IO(Port) gibi deklerasyon yapmanýz gerekir.
Normalde aksi belirtilmedikçe CCS dili sizin komutlarýnýza 
göre TRIS ayarlarýný otomatik olarak yapmaktadýr.
*/
set_tris_a (0x01); 
set_tris_b (0x00); 
output_b(0x00); 

 While(1){

/*
Aþaðýdaki komut ile PIN_B1'e baðlý led sürekli yanýp sönecektir.
Bu led, yüklenen programýnýzýn çalýþtýðýný gösterir ve siz de emin olursunuz
*/
output_toggle(pin_b1);

/*
Eðer A0 pin girdisi HIGH olursa B0 çýkýþý HIGH olsun,
deðilse B0 çýkýþý LOW olacak
*/
if (input(pin_a0)) 
         output_high(pin_b0);
         else
         output_low(pin_b0); 

/*
Tuþ takýmý okumalarýnda biraz gecikmeye ihtiyaç var
*/
Delay_Ms(100);

  }

 }
