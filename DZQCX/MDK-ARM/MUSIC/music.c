#include "music.h"
#include "tim.h"

char sta=0;
char Music_Num=6;

void BEEP1_TEXT(void)
{
	BEEP1_SOUND(M1,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M2,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M3,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M4,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M5,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M6,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(M7,1,Pai);
	BEEP1_SOUND(0,-1,Pai);
	BEEP1_SOUND(0,1,Pai);
	BEEP1_SOUND(0,2,Pai);
}
void BEEP2_TEXT(void)
{
	BEEP2_SOUND(M1,1,Pai);
  BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M2,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M3,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M4,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M5,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M6,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(M7,1,Pai);
	BEEP2_SOUND(0,-1,Pai);
	BEEP2_SOUND(0,1,Pai);
	BEEP2_SOUND(0,2,Pai);
}

void BEEP1_SOUND(unsigned short frq,short time,short pai)
{
	if(frq!=0)
	{
			PWM1_SET_VALUE(frq);
			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
			HAL_Delay(pai/time);
			HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
	}
	else
		if(time>=0)
		{
		  HAL_Delay(pai/time);
		}
		else
		{
			time=-time;
			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
			HAL_Delay(pai*time);
		  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
		}	
}

void BEEP2_SOUND(unsigned short frq,short time,short pai)
{
	if(frq!=0)
	{
			PWM2_SET_VALUE(frq);
			HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
			HAL_Delay(pai/time);
			HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
	}
	else
		if(time>=0)
		{
		  HAL_Delay(pai/time);
		}
		else
		{
			time=-time;
			HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
			HAL_Delay(pai*time);
		  HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
		}	
}

void BEEP1_PLAY(song_t song[],short pai)
{
	int i=0;
	HAL_Delay(500);
	
	while(sta)
	{
		
		if(song[i].time_num==0)
			break;
		else
			BEEP1_SOUND(song[i].freq,song[i].time_num,pai);
		
		i++;
		
	}
	
	BEEP1_SOUND(0,1,pai);
	BEEP1_SOUND(0,2,pai);

}

void BEEP2_PLAY(song_t song[],short pai)
{
	int i=0;
	HAL_Delay(500);
	
	while(sta)
	{
		
		if(song[i].time_num==0)
			break;
		else
			BEEP2_SOUND(song[i].freq,song[i].time_num,pai);
		
		i++;
	}
	
	BEEP2_SOUND(0,1,pai);
	BEEP2_SOUND(0,2,pai);

}

void USER_BEEP1(unsigned short frq)
{
	if(frq==0)HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
	else
	{
		PWM1_SET_VALUE(frq);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	}
}
void USER_BEEP2(unsigned short frq)
{
	if(frq==0)HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
	else
	{
		PWM2_SET_VALUE(frq);
		HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	}
}
