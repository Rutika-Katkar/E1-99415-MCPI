/*
 * my_led.c
 *
 *  Created on: 15-Sept-2026
 *      Author: sunbeam
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void led_init()
{
	RCC->AHB1ENR |= BV(3);
	GPIOD->MODER |= (BV(24)|BV(26)|BV(28)|BV(30));
	GPIOD->MODER &= ~(BV(25)|BV(27)|BV(29)|BV(31));
	GPIOD-> OTYPER &= ~(BV(12)|BV(13)|BV(14)|BV(15));//NO PULL UP
	GPIOD-> OSPEEDR &= ~(BV(24)|BV(25)|BV(26)|BV(27)|BV(28)|BV(29)|BV(30)|BV(31));//LOW SPEED
	GPIOD -> PUPDR &= ~(BV(24)|BV(25)|BV(26)|BV(27)|BV(28)|BV(29)|BV(30)|BV(31));//NO PULL UP OR PULL DOWN
}

/*void switch_init()
{
	RCC-> AHB1ENR |=BV(0);
	GPIOA->MODER &= ~(BV(0)|BV(1));
	//GPIOA->OTYPER &= ~(BV(0));
	GPIOA->OSPEEDR &= ~(BV(0)|BV(1));
	GPIOA ->PUPDR &= ~(BV(0)|BV(1));
}

int check_switch_press()
{
	BV(0) & GPIOA->IDR?1:0;
}
*/


void GREEN_led_on()
{
	GPIOD-> ODR |= (BV(12));
}

void GREEN_led_off()
{
	GPIOD->ODR &= ~(BV(12));
}

void ORANGE_led_on()
{
	GPIOD->ODR |=(BV(13));
}
void ORANGE_led_off()
{
	GPIOD->ODR &= ~(BV(13));
}

void RED_led_on()
{
	GPIOD->ODR |=(BV(14));
}

void RED_led_off()
{
	GPIOD->ODR &= ~(BV(14));
}

void BLUE_led_on()
{
	GPIOD->ODR |=(BV(15));
}

void BLUE_led_off()
{
	GPIOD->ODR &= ~(BV(15));
}






