/*
 * DRV_MSP430FR4133_DIGITALIO.h
 *
 *  Created on: Jul 27, 2020
 *      Author: fernandoks
 */

#ifndef DRV_MSP430FR4133_DIGITALIO_H_
#define DRV_MSP430FR4133_DIGITALIO_H_

#include <stdint.h>
#include <msp430.h>


#define ENABLE                      1
#define DISABLE                     0

#define PORT1                       0
#define PORT2                       1
#define PORT3                       2
#define PORT4                       3
#define PORT5                       4
#define PORT6                       5
#define PORT7                       6
#define PORT8                       7

#define PIN_AS_INPUT                0
#define PIN_AS_OUTPUT               1
#define PIN_RESISTOR_OFF            0
#define PIN_RESISTOR_ON             1
#define PIN_FUNCTION_GPIO           0
#define PIN_FUNCTION_PRIMARY        1
#define PIN_FUNCTION_SECONDARY      2
#define PIN_FUNCTION_TERTIARY       3



typedef struct
{
    uint8_t Port;
    uint8_t PinNumber;
    uint8_t Direction;
    uint8_t ResistorEnable;
    uint8_t Function;
} DIO_Handle_t;


DRVStatus_t DRV_DIO_Config(DIO_Handle_t* DIOHandle);
void DRV_SetPin(uint8_t Port, uint8_t Pin, uint8_t Enable);
void DRV_TogglePin(uint8_t Port, uint8_t Pin);
uint8_t DRV_ReadPin(uint8_t Port, uint8_t Pin);

static void DRV_DIO_Config_PORT1(DIO_Handle_t* DIOHandle);
static void DRV_DIO_Config_PORT2(DIO_Handle_t* DIOHandle);
static void DRV_DIO_Config_PORT3(DIO_Handle_t* DIOHandle);
static void DRV_DIO_Config_PORT4(DIO_Handle_t* DIOHandle);

#endif /* DRV_MSP430FR4133_DIGITALIO_H_ */
