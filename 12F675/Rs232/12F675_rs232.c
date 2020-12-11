
 /*********************************************
 *    dELAb - Deniz Elektronik Lab.           *
 *  PIC Geli�tirme Kart� i�in �rnek Program   *
 *                                            *
 *    PIC12F675 i�in RS232 KULLANIMI          *
 *                                            *
 *  - RS232 i�in JP3 Se�ili Olsun             *
 *  - Terminal program� 2400 Baud ayarl�      *
 *    olsun                                   *
 *********************************************/
 
#include "12F675.h"
#fuses INTRC,NOPUT,NOWDT,NOPROTECT,MCLR,NOBROWNOUT
#use delay(clock=4000000)
#use rs232(baud=2400,xmit=PIN_A2)

#use fast_io(a)

#rom 0x3ff = {0x3480} // Kalibrasyon de�eri !!!!!

main()
{

setup_adc_ports(NO_ANALOGS); 
setup_adc(ADC_OFF);
setup_comparator (NC_NC_NC_NC);

set_tris_a(0b111011); 

while(1)
{
printf("dELAb PIC Development Board");
Delay_Ms(200);
}

}
