#include "main.h"
#include "display7seg.h"
#include "timers.h"

int contador7seg=0;
int flag_count=1;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim==TIM3){
		if(flag_count){
			contador7seg++;
			if()
		}
	}
	if(htim==TIM4){
		Atualiza7seg(contador7seg);
	}
}






