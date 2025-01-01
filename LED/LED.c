#include"STC89C5xRC.h"
sbit LED0 = P1^0;   
sbit LED1 = P1^1;   
sbit LED2 = P1^2;   
sbit LED3 = P1^3;   
sbit LED4 = P1^4;   
sbit LED5 = P1^5;   
sbit LED6 = P1^6;  
sbit LED7 = P1^7;   

void delay(int time){
	int i;
	for(i=0;i<time;i++){
		}
}

void kedcotrol(unsigned char ledArray[8]){
	  LED0 = ledArray[0];
    LED1 = ledArray[1];
    LED2 = ledArray[2];
    LED3 = ledArray[3];
    LED4 = ledArray[4];
    LED5 = ledArray[5];
    LED6 = ledArray[6];
    LED7 = ledArray[7];

}
int i;
main(){
	unsigned char ledState[8] = {1, 0, 1, 0, 1, 0, 1, 0};
	while(1) {
        kedcotrol(ledState);  
                 
		
       for(i=0;i<8;i++){
				 ledState[i] = !ledState[i];
          delay(5000);   
			 }

	}
}


