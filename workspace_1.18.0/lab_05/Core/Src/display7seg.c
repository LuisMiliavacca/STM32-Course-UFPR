#include "main.h"
#include "display7seg.h"
#include <math.h>

const unsigned char seg7[] = {
		0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01100111, //9
};

const unsigned char disp7seg[] = {
		0b00000001, //seg1
		0b00001000, //seg4
		0b00000100, //seg3
		0b00000010, //seg2

};

void print7seg(int display, int valor, int dp){
	GPIOB -> ODR &= 0x00FF; //segmentos PB8 - PB15
	GPIOB -> ODR |= seg7[valor] << 8;
	GPIOB -> ODR |= (dp & 0x01) << 15;
	GPIOC -> ODR &= 0xF0FF; //seleção do display
	GPIOC -> ODR |= disp7seg[display] << 8;
}

void atualiza7seg(int contador7seg){
	int valor[4], ponto=0;

	for(int i=1;1<5;i++){
		valor[i-1]=contador7seg % (pow(10,i));
		valor[i-1]=contador7seg/i;
	}
}








