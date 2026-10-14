#include "main.h"
#include "modoA.h"
#include "modoC.h"
#include "modoD.h"
#include "interrup.h"
#include "timers.h"

char letras[3][8] = {{ //letras a serem escritas no 8x8
		0b01111100,  // █████
		0b01000100,  // █   █
		0b01000100,  // █   █
		0b01111100,  // █████
		0b01010000,  // █ █
		0b01001000,  // █  █
		0b01000100,  // █   █
		0b00000000
},{
		0b00111100,  //  █████
		0b01000010,  // █     █
		0b01000000,  // █
		0b01001110,  // █  ███
		0b01000010,  // █    █
		0b01000010,  // █    █
		0b00111100,  //  █████
		0b00000000   //
},{
		0b01111100,  // █████
		0b01000100,  // █   █
		0b01000100,  // █   █
		0b01111000,  // ████
		0b01000100,  // █   █
		0b01000100,  // █   █
		0b01111100,  // █████
		0b00000000   //
}};

void Print8x8(int letra, int linha){ //escreve a linha para a letra desejada na matriz de led
	GPIOC->ODR |= 0x00FF;             // Seleção da linha
	GPIOC->ODR &= 0xF0FF;             //
	GPIOB->ODR &= 0x00FF;             // Segmentos -> PB8 a PB15
	GPIOB->ODR |= letras[letra][linha] << 8;
	GPIOC->ODR &= ~(0x01 << (7-linha));
}

int flag_red=1,flag_green=0,flag_blue=0,flag_conf=0,i_int=1,i_config=0,letra;
float leitura_ADC;

void escrevefloat(float valor){ //escreve um numero float nos display 7seg
	int valorINT,algarismos[4],ponto;
	valor=valor*10;
	valorINT=(int)valor;
	algarismos[3]=valorINT/1000;
	algarismos[2]=(valorINT%1000)/100;
	algarismos[1]=((valorINT%1000)%100)/10;
	algarismos[0]=((valorINT%1000)%100)%10; //separa os 3 primeiros algarismos mais a priemira casa decimal
	if(curr7seg==1){
		ponto=1;
	}
	else{
		ponto=0;
	}

	print7seg(curr7seg, algarismos[curr7seg], ponto); //escreve o valor no 7seg
}










