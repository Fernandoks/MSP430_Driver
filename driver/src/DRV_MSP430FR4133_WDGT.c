/*
 * DRV_MSP430FR4133_WDGT.c
 *
 *  Created on: Jul 27, 2020
 *      Author: fernandoks
 */
#include <msp430.h>
#include "DRV_MSP430FR4133_WDGT.h"


void DRV_WTDG_Start(void)
{
    WDTCTL |= ( WDTPW & ~(1 << 7) );
}

void DRV_WTDG_Stop(void)
{
    WDTCTL = WDTPW | WDTHOLD;
}

void DRV_WTDG_Pet(void)
{
    WDTCTL = WDTPW | WDTCNTCL;
}

