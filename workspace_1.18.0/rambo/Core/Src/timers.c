#include "main.h"
#include "display7seg.h"
#include "timers.h"

int contador7seg = 0;
int flag_count = 1;
int flag_7seg = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //interrupção do timer
{
	if(htim->Instance == TIM3) //para o timer 3
	{
		if(flag_count)
		{
			contador7seg++; //conta contador7seg se flag_count=1
			if(contador7seg > 9999)
				contador7seg = 0;
		}
	}
	if(htim->Instance == TIM4)
	{
		flag_7seg = 1;
	}
}

