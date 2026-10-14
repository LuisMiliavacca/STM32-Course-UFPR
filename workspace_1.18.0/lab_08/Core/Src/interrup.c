#include "main.h"
#include "modoA.h"
#include "modoC.h"
#include "modoD.h"
#include "timers.h"
#include "interrup.h"
#include "ssd1306.h"
#include "fonts.h"

int i_cor=1;
int eixoX,eixoY,canalADC3=0;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) //interrupção do ADC que le o valor
{
	if(hadc->Instance == ADC1){
		leitura_ADC=HAL_ADC_GetValue(hadc);
		leitura_ADCpercent=(float)leitura_ADC*100/1024;
		valorPWM=(int)(leitura_ADCpercent*10);
	}
	if(hadc->Instance == ADC3){
		if(!canalADC3){
			eixoX=HAL_ADC_GetValue(hadc);
			HAL_ADC_Start_IT(&hadc3);
		}
		else{
			eixoY=HAL_ADC_GetValue(hadc);
		}
		canalADC3 ^= 0x01;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(flagA){
		if(GPIO_Pin & (0x2000)){
			if(flag_count==1){
				flag_count=0;
			}
			else{
				flag_count=1;
			}
		}
	}
	if(flagB){
		if((GPIO_Pin & (0x0004))==0){ //se botão 1 apertado
			flag_horario=1;
			flag_antihorario=0;
		}
		if((GPIO_Pin & (0x0010))==0){ //se botão 2 apertado
			flag_antihorario=1;
			flag_horario=0;
		}
	}
	if(flagC){
		if(GPIO_Pin & (0x0010)){
			i_cor++;
			if(i_cor>=4){
				i_cor=1;
			}
			if(i_cor==1){
				flag_red=1;
				flag_blue=0;
				flag_green=0;
			}
			else if(i_cor==2){
				flag_red=0;
				flag_blue=1;
				flag_green=0;
			}
			else if(i_cor==3){
				flag_red=0;
				flag_blue=0;
				flag_green=1;
			}
		}
	}
}









