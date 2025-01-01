#include "STC89C5xRC.h"

sbit button=P2^4;

void delay(int t);


main(){

 while(1){

	while(button==0){

	delay(3000);

		if(button==0){

		P1=0xff;

		delay(5000);

		P1=0x00;

		}
		return 0;

			}

		}

 }

void delay(int time){

 int i,j;

 for(i=0;i<time;i++){

	}

}