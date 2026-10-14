#include "main.h"
#include "display7seg.h"
#include "timers.h"
#include <math.h>

 const unsigned char seg7[] = { 0b00111111, //0
                                0b00000110, //1
	   	   			            0b01011011, //2
							    0b01001111, //3
							    0b01100110, //4
							    0b01101101, //5
							    0b01111101, //6
							    0b00000111, //7
							    0b01111111, //8
							    0b01100111  //9
};

const unsigned char disp7seg[] = {0b0000001, //SEG1
 		                          0b0001000, //SEG4
 								  0b0000100, //SEG3
 								  0b0000010  //SEG2
};
int curr7seg = 0;
void print7seg(int display, int valor, int dp)
{
	GPIOB->ODR &= 0x00FF;             // Segmentos -> PB8 a PB15
	GPIOB->ODR |= seg7[valor] << 8;
	GPIOB->ODR |= (dp & 0x01) << 15;
	GPIOC->ODR &= 0xF0FF;             // Seleção do display -> PC8 a PC11
	GPIOC->ODR |= disp7seg[display] << 8;
}
void Atualiza7seg(int contador7seg)
{
	int resto[4], ponto = 0;

	for(int i = 1; i< 5; i++)
	{
		resto[i-1] = contador7seg % (int)(pow(10.0f, (float)i));
		resto[i-1] = resto[i-1] / (int)(pow(10.0f, (float)i-1));
	}

	print7seg(curr7seg, resto[curr7seg], ponto);

	if(++curr7seg == 4)
		curr7seg = 0;
}
