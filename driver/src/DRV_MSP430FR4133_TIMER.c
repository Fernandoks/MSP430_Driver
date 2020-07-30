/*
 * DRV_MSP430FR4133_TIMER.c
 *
 *  Created on: Jul 28, 2020
 *      Author: fernandoks
 */

#include "DRV_MSP430FR4133.h"

#define ACLK    0x0100  // Timer_A ACLK source
#define UP      0x0010  // Timer_A UP mode

/*
 * TIMER 0
 */
void DRV_TIMER0_Config(void)
{
    TA0CTL = ACLK | UP;
}

DRVStatus_t DRV_TIMER0_SetCCR(uint16_t CCRValue)
{
    if (CCRValue > 0xFFFF)
    {
        return DRVStatus_error;
    }

    TA0CCR0 = CCRValue;
    return DRVStatus_ok;
}


uint8_t DRV_TIMER0_isFlagSet(void)
{
    return ( TA0CTL & TAIFG );
}

void DRV_TIMER0_ClearFlag(void)
{
    TA0CTL &= ~(TAIFG);
}

/*
 * TIMER 1
 */

void DRV_TIMER1_Config(void)
{
    TA1CTL = ACLK | UP;
}

DRVStatus_t DRV_TIMER1_SetCCR(uint16_t CCRValue)
{
    if (CCRValue > 0xFFFF)
    {
        return DRVStatus_error;
    }

    TA1CCR0 = CCRValue;
    return DRVStatus_ok;
}


uint8_t DRV_TIMER1_isFlagSet(void)
{
    return ( TA1CTL & TAIFG );
}

void DRV_TIMER1_ClearFlag(void)
{
    TA1CTL &= ~(TAIFG);
}




