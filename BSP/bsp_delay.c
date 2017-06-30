#include "bsp_delay.h"
#include "stm32f4xx.h"

static uint8_t  fac_us=21;	   
static uint16_t fac_ms=21000;

void delay_init(void)
{
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
  fac_us=21;//128M /8 =21M
  fac_ms=21000;
}

void delay_xms(uint16_t nms)
{	 		  	  
  uint32_t temp;		   
  SysTick->LOAD=(uint32_t)nms*fac_ms;
  SysTick->VAL =0x00;
  SysTick->CTRL=0x01 ;
  do
  {
    temp=SysTick->CTRL;
  }while((temp&0x01)&&!(temp&(1<<16)));
  SysTick->CTRL=0x00;
  SysTick->VAL =0X00;	  	    
} 

void delay_ms(uint16_t nms)
{
  uint8_t repeat=nms/500;
  uint16_t remain=nms%500;
  while(repeat)
  {
    delay_xms(500);
    repeat--;
  }
  if(remain)delay_xms(remain);
  
}

void delay_us(uint32_t nus)
{
  uint32_t temp;	    	 
  SysTick->LOAD=nus*fac_us;  		 
  SysTick->VAL=0x00;
  SysTick->CTRL=0x01 ;	 
  do
  {
    temp=SysTick->CTRL;
  }while((temp&0x01)&&!(temp&(1<<16)));
  SysTick->CTRL=0x00;
  SysTick->VAL =0X00;  
}
