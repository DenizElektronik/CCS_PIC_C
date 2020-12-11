
#define LCD_D4          PIN_B4
#define LCD_D5          PIN_B5
#define LCD_D6          PIN_B6
#define LCD_D7          PIN_B7
#define LCD_EN          PIN_B3
#define LCD_RS          PIN_B2

#define LINE_1          0x00
#define LINE_2          0x40
#define CLEAR_DISP      0x01

#use Standard_IO ( B )

void LCD_Init ( void );
void LCD_SetPosition ( unsigned int cX );
void LCD_PutChar ( unsigned int cX );
void LCD_PutCmd ( unsigned int cX );
void LCD_PulseEnable ( void );
void LCD_SetData ( unsigned int cX );

// **** LCD Kontrol Programý **** //

void LCD_Init ( void )
    {
    LCD_SetData ( 0x00 );
    delay_ms ( 200 );
    output_low ( LCD_RS );
    LCD_SetData ( 0x03 );
    LCD_PulseEnable();
    LCD_PulseEnable();
    LCD_PulseEnable();
    LCD_SetData ( 0x02 );
    LCD_PulseEnable();
    LCD_PutCmd ( 0x2C );
    LCD_PutCmd ( 0x0C );
    LCD_PutCmd ( 0x01 );
    LCD_PutCmd ( 0x06 );
    }

void LCD_SetPosition ( unsigned int cX )
    {
    LCD_SetData ( swap ( cX ) | 0x08 );
    LCD_PulseEnable();
    LCD_SetData ( swap ( cX ) );
    LCD_PulseEnable();
    }

void LCD_PutChar ( unsigned int cX )
    {
        output_high ( LCD_RS );
        LCD_SetData ( swap ( cX ) );
        LCD_PulseEnable();
        LCD_SetData ( swap ( cX ) );
        LCD_PulseEnable();
        output_low ( LCD_RS );
    }

void LCD_PutCmd ( unsigned int cX )
    {
    LCD_SetData ( swap ( cX ) );
    LCD_PulseEnable();
    LCD_SetData ( swap ( cX ) );
    LCD_PulseEnable();
    }

void LCD_PulseEnable ( void )
    {
    output_high ( LCD_EN );
    delay_us ( 3 );
    output_low ( LCD_EN );
    delay_ms ( 3 );
    }

void LCD_SetData ( unsigned int cX )
    {
    output_bit ( LCD_D4, cX & 0x01 );
    output_bit ( LCD_D5, cX & 0x02 );
    output_bit ( LCD_D6, cX & 0x04 );
    output_bit ( LCD_D7, cX & 0x08 );
    }

