#include "stm32f4xx.h"
#include "bsp_usart1.h"
#include "bsp_delay.h"

int main(void)
{
	int i=0;
	usart1_config();
	delay_init();
	while(1)
	{
		delay_ms(1000);
		printf("this is stm32f407 send %d\r\n",i++);
	}
	return 0;
}
