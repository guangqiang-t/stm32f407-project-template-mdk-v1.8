#ifndef _bsp_usart1_H_
#define _bsp_usart1_H_

#include <stdint.h>
#include <stdio.h>

extern void usart1_config(void);
extern void usart1_send_byte(uint8_t ch);

#endif
