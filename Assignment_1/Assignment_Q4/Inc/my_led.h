/*
 * my_led.h
 *
 *  Created on: 15-Sept-2026
 *      Author: sunbeam
 */

#ifndef MY_LED_H_
#define MY_LED_H_

//#define LED_PORT
#define GREEN_LED   12
#define ORANGE_LED  13
#define RED_LED     14
#define BLUE_LED    15

void led_init();
void switch_init();
int is_switch_press();


void GREEN_led_on();
void GREEN_led_off();
void ORANGE_led_on();
void ORANGE_led_off();
void RED_led_on();
void RED_led_off();
void BLUE_led_on();
void BLUE_led_off();

#endif /* MY_LED_H_ */
