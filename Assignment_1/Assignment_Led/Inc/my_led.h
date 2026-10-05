/*
 * led.h
 *
 *  Created on: 11-Sept-2026
 *      Author: kiran_z6dopa8
 */

#ifndef MY_LED_H_
#define MY_LED_H_

#include<stm32f4xx.h>

#define LED_PORT     GPIOD
#define GREEN_LED    12
#define ORANGE_LED   13
#define RED_LED      14
#define BLUE_LED     15


void led_init();
void led_on();
void led_off();
void led_alternate();
void led_alternate_reverse();

#endif /* MY_LED_H_ */
