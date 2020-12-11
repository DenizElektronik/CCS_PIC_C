/*

dELAb PIC Development Tool
(PIC Geliþtirme Kartý)
için tanýtým programý

- Tüm Jumper'lar açýk
- LED Switch'ler ON konumunda
- DISPLAY Switch'ler ON konumunda

Gerilim verildiðinde LCD, 7 Segment Display ve LED grubu
için demo programý çalýþacaktýr

*/

#include "16F876A.h"
#fuses HS,NOWDT,NOPUT,NOPROTECT,NOLVP,NOBROWNOUT,NOWRT
#use Delay(Clock=20000000)

#include "dELAb_LCD.c"

#byte PORTA = 5 /* PORTA Adresi */
#byte PORTB = 6 /* PORTB Adresi */
#byte PORTC = 7 /* PORTC Adresi */

// Segment Bilgileri:   0    1    2    3    4    5    6    7    8    9
byte const Digit[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};


void main ( void )
    {
    char cX;
    Byte Say, Basamak;

    setup_adc( ADC_OFF );
    set_tris_a(0b11110000);
    set_tris_b(0b00000000);

    While (True){

    PORTA = 0x00;

    cX = 1;

    LCD_Init();
    LCD_PutCmd ( CLEAR_DISP );
    LCD_SetPosition ( LINE_1 + 0 );
    printf ( LCD_PutChar, "**** dELAb **** ");
    LCD_SetPosition ( LINE_2 + 0 );
    printf ( LCD_PutChar, "PIC DEVELOPMENT " );

    for (Basamak=1;Basamak<5;Basamak++){

    if (Basamak==1) PORTA = 0x08; /* RA3 High - Birler */
    if (Basamak==2) PORTA = 0x04; /* RA2 High - Onlar  */
    if (Basamak==3) PORTA = 0x02; /* RA1 High - Yüzler */
    if (Basamak==4) PORTA = 0x01; /* RA0 High - Binler */

    for (Say=0;Say<10;Say++){
        PORTB= Digit[Say];
        Delay_Ms(200);

         }
      }

    set_tris_a(0b00000000);
    set_tris_b(0b00000000);
    set_tris_c(0b00000000);

    for (Say=0;Say<10;Say++){
    PORTA=0xFF;
    PORTB=0xFF;
    PORTC=0xFF;
    Delay_Ms(200);
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    Delay_Ms(200);
    }


   }
}

