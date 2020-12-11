
/**********************************************
*  �t���\����[��
*  File: LCDTerm.c
*
**********************************************/
#include <16f628a.h>
#fuses HS,NOWDT,PUT,NOPROTECT,NOLVP
#use delay(CLOCK = 20000000)
#use rs232(BAUD=9600, XMIT=PIN_B2, RCV=PIN_B1)
#use fast_io(B)
//// �萔��`
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
//// ���C���v���O����
void main(void)
{
	setup_comparator(NC_NC_NC_NC);		// �R���p���[�^�I�t
	set_tris_b(0x02);					// only RxD input 
	lcd_init();						// �t��������
	printf(lcd_data,"Start");			// �������b�Z�[�W
	/// ���C�����[�v
	while(1)	{
		output_toggle(PIN_A2);			// �ڈ�
		RcvData = getc();				// �P������M
		switch(RcvData) {				// ��M��������
			case 0x0D: break;		// ���s
			case 0x0A: break;
			case 0x1C: lcd_clear(); break;		//�t���N���A 
			case 0x1D: lcd_cmd(0x80); break;	// �P�s�ڐ擪
			case 0x1E: lcd_cmd(0xC0); break;	// �Q�s�ڐ擪
			default : lcd_data(RcvData); break;			
		}
	}	
}


///////////////////////////////////////////////
//  �t���\���퐧��֐��Q
//    lcd_init()    ----- ������
//    lcd_cmd(cmd)  ----- �R�}���h�o��
//    lcd_data(chr) ----- �P�����\���o��
//    lcd_clear()   ----- �S����
//    lcd_str(str)  ----- ������o��
//////////////////////////////////////////////

//////// �f�[�^�o�̓T�u�֐�
void lcd_out(int code, int flag){
	output_b(code & 0xF0);
	if (flag == 0)
		output_high(rs);		//�\���f�[�^�̏ꍇ
	else
		output_low(rs);		//�R�}���h�f�[�^�̏ꍇ
	delay_cycles(1);			//NOP		
	output_high(stb);			//strobe out
	delay_cycles(2);			//NOP
	output_low(stb);			//reset strobe
}
//////// �P�����\���֐�
void lcd_data(int asci){
	lcd_out(asci, 0);			//��ʂS�r�b�g�o��
	lcd_out(asci<<4, 0);		//���ʂS�r�b�g�o��
	delay_us(50);				//50��sec�҂�
}
/////// �R�}���h�o�͊֐�
void lcd_cmd(int cmd){
	lcd_out(cmd, 1);			//��ʂS�r�b�g�o��
	lcd_out(cmd<<4, 1);		//���ʂS�r�b�g�o��
	if((cmd & 0x03) != 0)
		delay_ms(2);			//2msec�҂�
	else
		delay_us(50);			//50usec�҂�
}
/////// �S�����֐�
void lcd_clear(){
	lcd_cmd(0x01);			//�������R�}���h�o��
	delay_ms(2);				//2msec�҂�
}
/////// ������o�͊֐�
void lcd_str(char *str){
	while(*str != 0x00)		//������̏I��蔻��
	{
		lcd_data(*str);		//������P�����o��
		str++;				//�|�C���^�{�P
	}
}
/////// �������֐�
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
