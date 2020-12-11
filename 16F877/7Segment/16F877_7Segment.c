/*

dELAb PIC Development Tool
(PIC Geli�tirme Kart�)
i�in tan�t�m program�

- T�m Jumper'lar a��k
- LED Switch'ler ON konumunda
- DISPLAY Switch'ler ON konumunda

Gerilim verildi�inde LCD, 7 Segment Display ve LED grubu
i�in demo program� �al��acakt�r

*/

#include "16F877A.h"
#fuses HS,NOWDT,NOPUT,NOPROTECT,NOLVP,NOBROWNOUT,NOWRT
#use Delay(Clock=20000000)

#include "dELAb_LCD.c"

#byte PORTA = 5 /* PORTA Adresi */
#byte PORTB = 6 /* PORTB Adresi */
#byte PORTC = 7 /* PORTC Adresi */
#byte PORTD = 8 /* PORTD Adresi */
#byte PORTE = 9 /* PORTE Adresi */

#define Birler  PORTA = 0x08; /* RA3 High - Birler */
#define Onlar   PORTA = 0x04; /* RA2 High - Onlar  */
#define Yuzler  PORTA = 0x02; /* RA1 High - Y�zler */
#define Binler  PORTA = 0x01; /* RA0 High - Binler */
#define Tumu    PORTA = 0x0F; /* T�m Basamaklar    */

#define a  0x01
#define b  0x02
#define c  0x04
#define d  0x08
#define e  0x10
#define f  0x20
#define g  0x40
#define dp 0x80

#define Bekle  200

void main ( void )
    {
    char cX;
    Byte Say, Basamak;

    setup_adc( ADC_OFF );
    set_tris_a(0b11110000);
    set_tris_b(0b00000000);

    PORTA = 0x00;

    cX = 1;

    LCD_Init();
    LCD_PutCmd ( CLEAR_DISP );
    LCD_SetPosition ( LINE_1 + 0 );
    printf ( LCD_PutChar, "**** dELAb **** ");
    LCD_SetPosition ( LINE_2 + 0 );
    printf ( LCD_PutChar, "PIC DEVELOPMENT " );

    While (True){

    PORTB = a;                      // Segment a Aktif
                Birler; 
                Delay_Ms(Bekle); 
                Onlar;  
                Delay_Ms(Bekle);
                Yuzler;
                Delay_Ms(Bekle);
                Binler;
                Delay_Ms(Bekle);                               
    PORTB = f;                      // Segment f Aktif
                Delay_Ms(Bekle);
    PORTB = e;                      // Segment e Aktif
                Delay_Ms(Bekle);
    PORTB = d;                      // Segment d Aktif
                Delay_Ms(Bekle);
                Yuzler;
                Delay_Ms(Bekle);
                Onlar;
                Delay_Ms(Bekle);
                Birler;
                Delay_Ms(Bekle);                
    PORTB = c;                      // Segment c Aktif
                Delay_Ms(Bekle); 
    PORTB = b;                      // Segment b Aktif
                Delay_Ms(Bekle); 

   }
}

