
 /*********************************************
 *    dELAb - Deniz Elektronik Lab.           *
 *  PIC Geliþtirme Kartý için Örnek Program   *
 *                                            *
 *    PIC12F675 için RS232 KULLANIMI          *
 *                                            *
 *  - RS232 için JP3 Seçili Olsun             *
 *  - Terminal programý 2400 Baud ayarlý      *
 *    olsun                                   *
 *********************************************/
 
#include "12F675.h"
#fuses INTRC,NOPUT,NOWDT,NOPROTECT,MCLR,NOBROWNOUT
#use delay(clock=4000000)
#use rs232(baud=2400,xmit=PIN_A2)

#use fast_io(a)

#rom 0x3ff = {0x3480} // Kalibrasyon deðeri !!!!!

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
