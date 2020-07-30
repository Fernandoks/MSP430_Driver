/*
 * DRV_MSP430FR4133_TIMER.h
 *
 *  Created on: Jul 28, 2020
 *      Author: fernandoks
 */

#ifndef DRIVER_INC_DRV_MSP430FR4133_TIMER_H_
#define DRIVER_INC_DRV_MSP430FR4133_TIMER_H_

#include <stdint.h>
#include <msp430.h>


void DRV_TIMER0_Config(void);
DRVStatus_t DRV_TIMER0_SetCCR(uint16_t CCRValue);
uint8_t DRV_TIMER0_isFlagSet(void);
void DRV_TIMER0_ClearFlag(void);

void DRV_TIMER1_Config(void);
DRVStatus_t DRV_TIMER1_SetCCR(uint16_t CCRValue);
uint8_t DRV_TIMER1_isFlagSet(void);
void DRV_TIMER1_ClearFlag(void);

#endif /* DRIVER_INC_DRV_MSP430FR4133_TIMER_H_ */
