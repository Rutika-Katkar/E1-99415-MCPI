/*
 * my_led.c
 *
 *  Created on: 11-Sept-2026
 *      Author: kiran_z6dopa8
 */

#include"my_led.h"
void led_init()
{
	//LED Initalisation
	//Enable clock for GPIOD
		RCC->AHB1ENR |= BV(3);
	//SET GPIO D12, D13, D14, D15 as output
		LED_PORT->MODER |=  ( BV(24)|BV(26)| BV(28)|BV(30));
		LED_PORT->MODER &= ~( BV(25)|BV(27)| BV(29)|BV(31));
	// Set GPIO D12, D13, D14, D15 as push pull
		LED_PORT->OTYPER &= ~(  BV(12)|BV(13)| BV(14)|BV(15)  );
	//SET GPIO D12, D13, D14, D15 as low speed
		LED_PORT->OSPEEDR &= ~(  BV(24)| BV(25)| BV(26)| BV(27)| BV(28)| BV(29)| BV(30)|BV(31));
	//SET GPIO D12, D13, D14, D15 as no pull up no pull down
		LED_PORT->PUPDR &= ~(  BV(24)| BV(25)| BV(26)| BV(27)| BV(28)| BV(29)| BV(30)|BV(31));

}
void Green_led_on()
{
	//write 1 on ODR register to ON due to common cathode
	LED_PORT->ODR |= ( BV(GREEN_LED));
}

void Green_led_off()
{
	//write 0 on ODR register to OFF due to common cathode
	LED_PORT->ODR &= ~( BV(GREEN_LED));
}
void Orange_led_on()
{
	//write 1 on ODR register to ON due to common cathode
	LED_PORT->ODR |= ( BV(ORANGE_LED));
}

void Orange_led_off()
{
	//write 0 on ODR register to OFF due to common cathode
	LED_PORT->ODR &= ~( BV(ORANGE_LED));
}

void Red_led_on()
{
	//write 1 on ODR register to ON due to common cathode
	LED_PORT->ODR |= ( BV(RED_LED));
}

void Red_led_off()
{
	//write 0 on ODR register to OFF due to common cathode
	LED_PORT->ODR &= ~( BV(RED_LED));
}

void Blue_led_on()
{
	//write 1 on ODR register to ON due to common cathode
	LED_PORT->ODR |= ( BV(BLUE_LED));
}

void Blue_led_off()
{
	//write 0 on ODR register to OFF due to common cathode
	LED_PORT->ODR &= ~( BV(BLUE_LED));
}













