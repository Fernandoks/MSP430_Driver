/***************************************************************************************
 *  MSP430 Blink the LED Demo - Software Toggle P1.0
 *
 * Clock Y1 32768
 * MCLK 2MHz, SMCLCK 2MHz, ACLK 32768Hz
 ***************************************************************************************/

#include <msp430.h>
#include "DRV_MSP430FR4133.h"


/*
 * LED RED P1.0
 * LED GREEN P4.0
 * S1 P1.2
 * S2 P2.6
 * S3 RST
 */
#define ACLK_BASE           32768
#define LED_RED_PORT        PORT1
#define LED_RED_PIN         0
#define LED_GREEN_PORT      PORT4
#define LED_GREEN_PIN       0
#define S1_PORT             PORT1
#define S1_PIN              2
#define S2_PORT             PORT2
#define S2_PIN              6

void GPIO_config(void);

void main(void)
{
    volatile static uint8_t clicks = 1;
    uint8_t first_click = 0;

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    GPIO_config();

    DRV_TIMER0_Config();
    DRV_TIMER1_Config();

    DRV_SetPin(LED_RED_PORT, LED_RED_PIN, ENABLE);
    DRV_SetPin(LED_GREEN_PORT, LED_GREEN_PIN, ENABLE);

    DRV_TIMER0_SetCCR(ACLK_BASE/clicks);
    DRV_TIMER1_SetCCR(ACLK_BASE);

    while(1)
    {
        first_click = 0;

        while ( DRV_ReadPin(S1_PORT, S1_PIN) == 0 )
        {
            //DRV_SetPin(LED_RED_PORT, LED_RED_PIN, DISABLE);
            if(first_click == 0)
            {
                clicks++;
                first_click = 1;
                DRV_TIMER0_SetCCR(ACLK_BASE/clicks);
            }
            if (clicks >= 10)
            {
                clicks = 1;
                DRV_TIMER0_SetCCR(ACLK_BASE/clicks);
            }
        }

        if ( DRV_TIMER0_isFlagSet() == 1 )
        {
            DRV_TogglePin(LED_RED_PORT, LED_RED_PIN);
            DRV_TIMER0_ClearFlag();
        }

        if ( DRV_TIMER1_isFlagSet() == 1 )
        {
           DRV_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
           DRV_TIMER1_ClearFlag();
        }

    }

}

void GPIO_config()
{
    DIO_Handle_t LED_Red;
    LED_Red.Port = LED_RED_PORT;
    LED_Red.Direction = PIN_AS_OUTPUT;
    LED_Red.PinNumber = LED_RED_PIN;
    LED_Red.ResistorEnable = PIN_RESISTOR_OFF;
    LED_Red.Function = PIN_FUNCTION_GPIO;
    DRV_DIO_Config(&LED_Red);

    DIO_Handle_t LED_Green;
    LED_Green.Port = LED_GREEN_PORT;
    LED_Green.Direction = PIN_AS_OUTPUT;
    LED_Green.PinNumber = LED_GREEN_PIN;
    LED_Green.ResistorEnable = PIN_RESISTOR_OFF;
    LED_Green.Function = PIN_FUNCTION_GPIO;
    DRV_DIO_Config(&LED_Green);

    DIO_Handle_t S1;
    S1.Port = S1_PORT;
    S1.Direction = PIN_AS_INPUT;
    S1.PinNumber = S1_PIN;
    S1.ResistorEnable = PIN_RESISTOR_ON;
    S1.Function = PIN_FUNCTION_GPIO;
    DRV_DIO_Config(&S1);
}


