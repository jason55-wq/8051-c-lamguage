#include"STC89C5xRC.h"
#define u8 unsigned char
#define u16 unsigned int
		u8 keyNum=0xff;
//延時函數
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
//鍵盤掃描子程序1
u8 keys_Scan1(){
	u8 keyNo=0xff;
	if (P2 ==0x0f) return 0xff;//無按鍵被按下時提前否回
	//按下按鍵後00001111將變成0000xxxx,x中1個=0,3個人仍=1
	//下面判斷被按下的按鍵為0-3其中一列
	switch(P2 & 0x0f){
		case 0x0e: keyNo=0; break;//在第0列
		case 0x0D: keyNo=1; break;//在第1列
		case 0x0B: keyNo=2; break;//在第2列
		case 0x07: keyNo=3; break;//在第3列
		default: return 0xff;
	}
	switch(P2 & 0xf0){
		case 0xe0: keyNo+=0; break;//在第0行
		case 0xD0: keyNo+=4; break;//在第1行
		case 0xB0: keyNo+=8; break;//在第2行
		case 0x70: keyNo+=12; break;//在第3行
		default: return 0xff;
	}
	return keyNo;
}

//主程式
int main(){
	P1=0XFF;
	 while (1) {
        keyNum = keys_Scan1();  // 掃描按鍵

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
