#ifndef __TIMERS_H
#define __TIMERS_H

#include "main.h"

extern int flag_conf;
extern int i_config;
extern int flagA;
extern int flagB;
extern int flagC;
extern int flagD;
extern int flag_red;
extern int flag_green;
extern int flag_blue;
extern int flag_horario;
extern int flag_antihorario;
extern int linha;
extern int eixoX;
extern int eixoY;
extern int flagOLED;
extern char cont7seg_OLED[];
extern char N_OLED[];
extern char valorPWM_OLED[];
extern char eixoX_OLED[];
extern char eixoY_OLED[];
extern int flagBT;

extern int N;
extern int i;
extern float leitura_ADCpercent;

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart5;

void Print8x8(int,int);



#endif
