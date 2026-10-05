/*
 * lis3dsh.c
 *
 *  Created on: 24-Sept-2026
 *      Author: sunbeam
 */


#include "lis3dsh.h"

extern SPI_HandleTypeDef hspi1;

void Accel_Write(uint8_t int_addr, uint8_t data[], uint8_t size)
{
    // Enable accelerometer: PE3 = 0
    HAL_GPIO_WritePin(ACCEL_CE_GPIO,
                      ACCEL_CE_GPIO_PIN,
                      GPIO_PIN_RESET);

    // Write operation: MSB = 0
    int_addr &= ~(1 << 7);

    // Send internal register address
    HAL_SPI_Transmit(&hspi1,
                     &int_addr,
                     1,
                     HAL_MAX_DELAY);

    // Send data
    HAL_SPI_Transmit(&hspi1,
                     data,
                     size,
                     HAL_MAX_DELAY);

    // Disable accelerometer: PE3 = 1
    HAL_GPIO_WritePin(ACCEL_CE_GPIO,
                      ACCEL_CE_GPIO_PIN,
                      GPIO_PIN_SET);
}


void Accel_Read(uint8_t int_addr, uint8_t data[], uint8_t size)
{
    // Enable accelerometer: PE3 = 0
    HAL_GPIO_WritePin(ACCEL_CE_GPIO,
                      ACCEL_CE_GPIO_PIN,
                      GPIO_PIN_RESET);

    // Read operation: MSB = 1
    int_addr |= (1 << 7);

    // Send internal register address
    HAL_SPI_Transmit(&hspi1,
                     &int_addr,
                     1,
                     HAL_MAX_DELAY);

    // Receive data
    HAL_SPI_Receive(&hspi1,
                    data,
                    size,
                    HAL_MAX_DELAY);

    // Disable accelerometer: PE3 = 1
    HAL_GPIO_WritePin(ACCEL_CE_GPIO,
                      ACCEL_CE_GPIO_PIN,
                      GPIO_PIN_SET);
}


void Accel_Init(void)
{
    // Enable X, Y, Z axes
    // Set output data rate
    uint8_t cr4_val = ACCEL_CR4_XYZEN | ACCEL_CR4_ODR25;

    Accel_Write(ACCEL_CR4,
                &cr4_val,
                1);
}


void Accel_WaitForReading(void)
{
    uint8_t sr_val;

    do
    {
        Accel_Read(ACCEL_STATUS,
                   &sr_val,
                   1);

    } while ((sr_val & ACCEL_SR_XYZDA) == 0);
}


AccelReading_t Accel_GetReading(void)
{
    uint8_t data[2];
    AccelReading_t val;

    // Wait until new X, Y, Z data is available
    Accel_WaitForReading();


    // ---------------- X AXIS ----------------
    Accel_Read(ACCEL_XL,
               data,
               2);

    val.x = (int16_t)(((uint16_t)data[1] << 8) | data[0]);


    // ---------------- Y AXIS ----------------
    Accel_Read(ACCEL_YL,
               data,
               2);

    val.y = (int16_t)(((uint16_t)data[1] << 8) | data[0]);


    // ---------------- Z AXIS ----------------
    Accel_Read(ACCEL_ZL,
               data,
               2);

    val.z = (int16_t)(((uint16_t)data[1] << 8) | data[0]);


    return val;
}
