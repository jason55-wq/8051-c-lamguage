#include"STC89C5xRC.h"
#define u8 unsigned char
#define u16 unsigned int
		u8 keyNum=0xff;
//���ɨ��
void Delay100us(){
	u8 i=2,j=39;
	do{
		while(--j);
	}while(--i);
}

void Delayms(){
	u8 i=12,j=169;
	do{
		while(--j);
	}while(--i);
}
//............................................................................................
void delay_ms(u8 x){while(x--) Delayms();}
void delay_nx100us(u8 x){while(x--) Delay100us();}
//.............................................................................................
//��L���y�l�{��1
u8 keys_Scan1(){
	u8 keyNo=0xff;
	if (P2 ==0x0f) return 0xff;//�L����Q���U�ɴ��e�_�^
	//���U�����00001111�N�ܦ�0000xxxx,x��1��=0,3�ӤH��=1
	//�U���P�_�Q���U�����䬰0-3�䤤�@�C
	switch(P2 & 0x0f){
		case 0x0e: keyNo=0; break;//�b��0�C
		case 0x0D: keyNo=1; break;//�b��1�C
		case 0x0B: keyNo=2; break;//�b��2�C
		case 0x07: keyNo=3; break;//�b��3�C
		default: return 0xff;
	}
	switch(P2 & 0xf0){
		case 0xe0: keyNo+=0; break;//�b��0��
		case 0xD0: keyNo+=4; break;//�b��1��
		case 0xB0: keyNo+=8; break;//�b��2��
		case 0x70: keyNo+=12; break;//�b��3��
		default: return 0xff;
	}
	return keyNo;
}

//�D�{��
int main(){
	P1=0XFF;
	 while (1) {
        keyNum = keys_Scan1();  // ���y����

        if (keyNum != 0xff) { 
            P1 = 0x00;         
            delay_ms(500);     
            P1 = 0xff;         
            delay_ms(500);     
        }
        delay_ms(10);  
			}
	 return 0;
		
}
