#include "stm32f4xx.h"
#include "bsp_usart1.h"
#include "bsp_delay.h"

int main(void)
{
	int i=0;
	usart1_config();
	delay_init();
//	RCC_AHB1PeriphClockCmd(RCC_APB2Periph_SPI4, ENABLE);
	while(1)
	{
		delay_ms(1000);
		printf("this is stm32f407 send %d\r\n",i++);
	}
//	return 0;
}



//-------------------------------------------------------------------------//
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number, */
  printf("Wrong parameters value: file %s on line %d\r\n", file, line);

  /* Infinite loop */
  while (1)
  {
		;
  }
}
#endif
