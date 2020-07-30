/*
 * DRV_MSP430FR4133_DIGITALIO.c
 *
 *  Created on: Jul 27, 2020
 *      Author: fernandoks
 */



#include "DRV_MSP430FR4133.h"

DRVStatus_t DRV_DIO_Config(DIO_Handle_t* DIOHandle)
{
    DRVStatus_t status = DRVStatus_error;

    switch(DIOHandle->Port)
    {
    case PORT1:
        DRV_DIO_Config_PORT1(DIOHandle);
        status = DRVStatus_ok;
        break;
    case PORT2:
        DRV_DIO_Config_PORT2(DIOHandle);
        status = DRVStatus_ok;
        break;
    case PORT3:
        DRV_DIO_Config_PORT3(DIOHandle);
        status = DRVStatus_ok;
        break;
    case PORT4:
        DRV_DIO_Config_PORT4(DIOHandle);
        status = DRVStatus_ok;
        break;
    case PORT5:
        status = DRVStatus_error;
        break;
    case PORT6:
        status = DRVStatus_error;
        break;
    case PORT7:
        status = DRVStatus_error;
        break;
    case PORT8:
        status = DRVStatus_error;
        break;
    default:
      break;
    }
    return status;
}


void DRV_SetPin(uint8_t Port, uint8_t Pin, uint8_t Enable)
{
    if (Enable == ENABLE)
    {
        switch(Port)
        {
        case PORT1:
           P1OUT |= (1 << Pin);
           break;
        case PORT2:
           P2OUT |= (1 << Pin);
           break;
        case PORT3:
           P3OUT |= (1 << Pin);
           break;
        case PORT4:
           P4OUT |= (1 << Pin);
           break;
        case PORT5:
           P5OUT |= (1 << Pin);
           break;
        case PORT6:
           P6OUT |= (1 << Pin);
           break;
        case PORT7:
           P7OUT |= (1 << Pin);
           break;
        case PORT8:
           P8OUT |= (1 << Pin);
           break;
        default:
           break;
        }
    }
    else
    {
        switch(Port)
        {
        case PORT1:
           P1OUT &= ~(1 << Pin);
           break;
        case PORT2:
           P2OUT &= ~(1 << Pin);
           break;
        case PORT3:
           P3OUT &= ~(1 << Pin);;
           break;
        case PORT4:
           P4OUT &= ~(1 << Pin);
           break;
        case PORT5:
           P5OUT &= ~(1 << Pin);
           break;
        case PORT6:
           P6OUT &= ~(1 << Pin);
           break;
        case PORT7:
           P7OUT &= ~(1 << Pin);
           break;
        case PORT8:
           P8OUT &= ~(1 << Pin);
           break;
        default:
           break;
        }
    }
}

void DRV_TogglePin(uint8_t Port, uint8_t Pin)
{
    switch(Port)
    {
    case PORT1:
       P1OUT ^= (1 << Pin);
       break;
    case PORT2:
       P2OUT ^= (1 << Pin);
       break;
    case PORT3:
       P3OUT ^= (1 << Pin);
       break;
    case PORT4:
       P4OUT ^= (1 << Pin);
       break;
    case PORT5:
       P5OUT ^= (1 << Pin);
       break;
    case PORT6:
       P6OUT ^= (1 << Pin);
       break;
    case PORT7:
       P7OUT ^= (1 << Pin);
       break;
    case PORT8:
       P8OUT ^= (1 << Pin);
       break;
    default:
       break;
    }

}

uint8_t DRV_ReadPin(uint8_t Port, uint8_t Pin)
{
    uint8_t value;

    switch(Port)
    {
    case PORT1:
       value = ( (P1IN & (1 << Pin)) >> Pin );
       break;
    case PORT2:
       value = ( (P2IN & (1 << Pin)) >> Pin );
       break;
    case PORT3:
       value = ( (P3IN & (1 << Pin)) >> Pin );
       break;
    case PORT4:
       value = ( (P4IN & (1 << Pin)) >> Pin );
       break;
    case PORT5:
       value = ( (P5IN & (1 << Pin)) >> Pin );
       break;
    case PORT6:
       value = ( (P6IN & (1 << Pin)) >> Pin );
       break;
    case PORT7:
       value = ( (P7IN & (1 << Pin)) >> Pin );
       break;
    case PORT8:
       value = ( (P8IN & (1 << Pin)) >> Pin );
       break;
    default:
       value = 0xFF;
       break;
    }

    return value;
}


/**********************************************************************************
 *
 * Static functions
 *
 **********************************************************************************/


static void DRV_DIO_Config_PORT1(DIO_Handle_t* DIOHandle)
{
    //Sets direction
    P1DIR |= (DIOHandle->Direction << DIOHandle->PinNumber);

    //Enable Pullup or Pulldown
    P1REN |= (DIOHandle->ResistorEnable << DIOHandle->PinNumber);

    //Selection pin function
    if (DIOHandle->Function == PIN_FUNCTION_GPIO)
    {
        P1SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P1SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_PRIMARY)
    {
        P1SEL0 |= (1 << DIOHandle->PinNumber);
        //P1SEL1 &= ~(1 << DIOHandle->PinNumber);

    }
    else if (DIOHandle->Function == PIN_FUNCTION_SECONDARY)
    {
        P1SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P1SEL1 |= (1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_TERTIARY)
    {
        P1SEL0 |= (1 << DIOHandle->PinNumber);
        //P1SEL1 |= (1 << DIOHandle->PinNumber);
    }
}



static void DRV_DIO_Config_PORT2(DIO_Handle_t* DIOHandle)
{
    //Sets direction
    P2DIR |= (DIOHandle->Direction << DIOHandle->PinNumber);

    //Enable Pullup or Pulldown
    P2REN |= (DIOHandle->ResistorEnable << DIOHandle->PinNumber);

    //Selection pin function
    if (DIOHandle->Function == PIN_FUNCTION_GPIO)
    {
        P2SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P2SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_PRIMARY)
    {
        P2SEL0 |= (1 << DIOHandle->PinNumber);
        //P2SEL1 &= ~(1 << DIOHandle->PinNumber);

    }
    else if (DIOHandle->Function == PIN_FUNCTION_SECONDARY)
    {
        P2SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P2SEL1 |= (1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_TERTIARY)
    {
        P2SEL0 |= (1 << DIOHandle->PinNumber);
        //P2SEL1 |= (1 << DIOHandle->PinNumber);
    }
}


static void DRV_DIO_Config_PORT3(DIO_Handle_t* DIOHandle)
{
    //Sets direction
    P3DIR |= (DIOHandle->Direction << DIOHandle->PinNumber);

    //Enable Pullup or Pulldown
    P3REN |= (DIOHandle->ResistorEnable << DIOHandle->PinNumber);

    //Selection pin function
    if (DIOHandle->Function == PIN_FUNCTION_GPIO)
    {
        P3SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P3SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_PRIMARY)
    {
        P3SEL0 |= (1 << DIOHandle->PinNumber);
        //P3SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_SECONDARY)
    {
        P3SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P3SEL1 |= (1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_TERTIARY)
    {
        P3SEL0 |= (1 << DIOHandle->PinNumber);
        //P3SEL1 |= (1 << DIOHandle->PinNumber);
    }
}


static void DRV_DIO_Config_PORT4(DIO_Handle_t* DIOHandle)
{
    //Sets direction
    P4DIR |= (DIOHandle->Direction << DIOHandle->PinNumber);

    //Enable Pullup or Pulldown
    P4REN |= (DIOHandle->ResistorEnable << DIOHandle->PinNumber);

    //Selection pin function
    if (DIOHandle->Function == PIN_FUNCTION_GPIO)
    {
        P4SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P4SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_PRIMARY)
    {
        P4SEL0 |= (1 << DIOHandle->PinNumber);
        //P4SEL1 &= ~(1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_SECONDARY)
    {
        P4SEL0 &= ~(1 << DIOHandle->PinNumber);
        //P4SEL1 |= (1 << DIOHandle->PinNumber);
    }
    else if (DIOHandle->Function == PIN_FUNCTION_TERTIARY)
    {
        P4SEL0 |= (1 << DIOHandle->PinNumber);
        //P4SEL1 |= (1 << DIOHandle->PinNumber);
    }
}
