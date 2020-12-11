
/**********************************************
*  液晶表示器端末
*  File: LCDTerm.c
*
**********************************************/
#include <16f628a.h>
#fuses HS,NOWDT,PUT,NOPROTECT,NOLVP
#use delay(CLOCK = 20000000)
#use rs232(BAUD=9600, XMIT=PIN_B2, RCV=PIN_B1)
#use fast_io(B)
//// 定数定義
#define rs	PIN_A1
#define stb	PIN_A0
//// Global Variables
char RcvData;
/// prototype
void lcd_data(int asci);
void lcd_cmd(int cmd);
void lcd_clear();
void lcd_init();
void lcd_str(char *str);
//// メインプログラム
void main(void)
{
	setup_comparator(NC_NC_NC_NC);		// コンパレータオフ
	set_tris_b(0x02);					// only RxD input 
	lcd_init();						// 液晶初期化
	printf(lcd_data,"Start");			// 初期メッセージ
	/// メインループ
	while(1)	{
		output_toggle(PIN_A2);			// 目印
		RcvData = getc();				// １文字受信
		switch(RcvData) {				// 受信文字判定
			case 0x0D: break;		// 改行
			case 0x0A: break;
			case 0x1C: lcd_clear(); break;		//液晶クリア 
			case 0x1D: lcd_cmd(0x80); break;	// １行目先頭
			case 0x1E: lcd_cmd(0xC0); break;	// ２行目先頭
			default : lcd_data(RcvData); break;			
		}
	}	
}


///////////////////////////////////////////////
//  液晶表示器制御関数群
//    lcd_init()    ----- 初期化
//    lcd_cmd(cmd)  ----- コマンド出力
//    lcd_data(chr) ----- １文字表示出力
//    lcd_clear()   ----- 全消去
//    lcd_str(str)  ----- 文字列出力
//////////////////////////////////////////////

//////// データ出力サブ関数
void lcd_out(int code, int flag){
	output_b(code & 0xF0);
	if (flag == 0)
		output_high(rs);		//表示データの場合
	else
		output_low(rs);		//コマンドデータの場合
	delay_cycles(1);			//NOP		
	output_high(stb);			//strobe out
	delay_cycles(2);			//NOP
	output_low(stb);			//reset strobe
}
//////// １文字表示関数
void lcd_data(int asci){
	lcd_out(asci, 0);			//上位４ビット出力
	lcd_out(asci<<4, 0);		//下位４ビット出力
	delay_us(50);				//50μsec待ち
}
/////// コマンド出力関数
void lcd_cmd(int cmd){
	lcd_out(cmd, 1);			//上位４ビット出力
	lcd_out(cmd<<4, 1);		//下位４ビット出力
	if((cmd & 0x03) != 0)
		delay_ms(2);			//2msec待ち
	else
		delay_us(50);			//50usec待ち
}
/////// 全消去関数
void lcd_clear(){
	lcd_cmd(0x01);			//初期化コマンド出力
	delay_ms(2);				//2msec待ち
}
/////// 文字列出力関数
void lcd_str(char *str){
	while(*str != 0x00)		//文字列の終わり判定
	{
		lcd_data(*str);		//文字列１文字出力
		str++;				//ポインタ＋１
	}
}
/////// 初期化関数
void lcd_init(){
	delay_ms(15);
	lcd_out(0x30, 1);			//8bit mode set
	delay_ms(5);
	lcd_out(0x30, 1);			//8bit mode set
	delay_ms(1);
	lcd_out(0x30, 1);			//8bit mode set
	delay_ms(1);
	lcd_out(0x20, 1);			//4bit mode set
	delay_ms(1);
	lcd_cmd(0x2E);			//DL=0 4bit mode
	lcd_cmd(0x08);			//display off C=D=B=0
	lcd_cmd(0x0D);			//display on C=D=1 B=0
	lcd_cmd(0x06);			//entry I/D=1 S=0
	lcd_cmd(0x02);			//cursor home
}
