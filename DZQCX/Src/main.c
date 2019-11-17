/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "music.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void USER_Judge(char ch);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t SWT='0';
uint8_t SWG='0';
char i=0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(1000);
  char c='q';
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_UART_Receive(&huart3,&SWT,sizeof(SWT),10);
		HAL_Delay(10);
	  if(SWT!=c)
	  {
	    USER_Judge(SWT);
			c=SWT;
 			if(SWT=='0')c='q';
	  }
		
		while(SWT=='K')
		{ 
			HAL_UART_Receive_IT(&huart3,&SWG,sizeof(SWG));
			if(i==0)
			{
				HAL_Delay(10);
			}
			if(i==1)
			{ 
				sta=1;
			  HAL_Delay(100);
			  BEEP1_PLAY(Song_Bie,620);
			}
			if(i==2)
			{
				sta=1;
				HAL_Delay(100);
			  BEEP1_PLAY(Hua_Huo,600);
			}
			if(i==3)
			{
				sta=1;
				HAL_Delay(100);
			  BEEP1_PLAY(Qian_QQ_Shi,320);
			}
			if(i==4)
			{
				sta=1;
				HAL_Delay(100);
			  BEEP1_PLAY(molihua,800);
			}
			if(i==5)
			{
				sta=1;
				HAL_Delay(100);
			  BEEP1_PLAY(muyangqu,800);
			}
			if(i==6)
			{
				sta=1;
				HAL_Delay(100);
			  BEEP1_PLAY(Shen_Hua,600);
			}
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
int fputc( int dat, FILE *file )
{
    uint8_t ch = dat;
    HAL_UART_Transmit(&huart3,&ch,1,100 );
	return 0;
}

void USER_Judge(char ch)
{
	switch(ch)
	{
		case 'a':
			USER_BEEP1(L1);
		  break;
		case 'b':
			USER_BEEP1(L2);
		  break;
		case 'c':
			USER_BEEP1(L3);
		  break;
		case 'd':
			USER_BEEP1(L4);
		  break;
		case 'e':
			USER_BEEP1(L5);
		  break;
		case 'f':
			USER_BEEP1(L6);
		  break;
		case 'g':
			USER_BEEP1(L7);
		  break;
		case '1':
			USER_BEEP1(M1);
		  break;
		case '2':
			USER_BEEP1(M2);
		  break;
		case '3':
			USER_BEEP1(M3);
		  break;
		case '4':
			USER_BEEP1(M4);
		  break;
		case '5':
			USER_BEEP1(M5);
		  break;
		case '6':
			USER_BEEP1(M6);
		  break;
		case '7':
			USER_BEEP1(M7);
		  break;
		case 'A':
			USER_BEEP1(H1);
		  break;
		case 'B':
			USER_BEEP1(H2);
		  break;
		case 'C':
			USER_BEEP1(H3);
		  break;
		case 'D':
			USER_BEEP1(H4);
		  break;
		case 'E':
			USER_BEEP1(H5);
		  break;
		case 'F':
			USER_BEEP1(H6);
		  break;
		case 'G':
			USER_BEEP1(H7);
		  break;
		case '0':
			USER_BEEP1(0);
		  break;
		default:
			break;
	}
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==huart3.Instance)
	{
		while(SWG=='Z')
		{
			sta=1;
			USER_BEEP1(0);
			HAL_UART_Receive(&huart3,&SWG,sizeof(SWG),50);
		}
		if(SWG=='L')
		{
			sta=0;
			SWT='0';
			i=0;
		}
		if(SWG=='K')
		{ 
			if(i==0)i=1;
			sta=1;
			USER_BEEP1(0);
			HAL_UART_Receive_IT(&huart3,&SWG,sizeof(SWG));
		}
		if(SWG=='Q')
		{
			sta=0;
		  i=(i+Music_Num)%Music_Num+1;
			HAL_UART_Receive_IT(&huart3,&SWG,sizeof(SWG));
		}
		if(SWG=='H')
		{
			sta=0;
			i=(i-1+Music_Num)%Music_Num;
			if(i==0)i=Music_Num;
			HAL_UART_Receive_IT(&huart3,&SWG,sizeof(SWG));
		}
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
