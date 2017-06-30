#ifndef _bsp_delay_H_
#define _bsp_delay_H_

#include <stdint.h>

extern void delay_init(void);
extern void delay_ms(uint16_t nms);
extern void delay_us(uint32_t nus);

#endif
