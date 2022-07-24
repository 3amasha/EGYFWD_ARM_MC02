 /******************************************************************************
 *
 * Module: ModuleTest
 *
 * File Name: Dio_ModuleTest.c
 *
 * Description: Source file for the Dio Test Cases.
 *
 
 ******************************************************************************/
#include <assert.h>
#include "Dio.h"
#include "tm4c123gh6pm_registers.h"

#define DIO_INVALIDE_CHANNEL_NUM 50










/************************************************************************************
* Test ID :TestCase5
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press SW1(PF4) then the Red led(PF1) shall be turned on.
*                  2. Press SW2(PF0) then the Red led(PF1) shall be turned off.
*************************************************************************************/
void TestCase5(void)
{
    uint8 SW1_Value = STD_HIGH;
    uint8 SW2_Value = STD_HIGH;

    /* Wait until the SW1 is pressed */
    while(SW1_Value != STD_LOW)
    {
        SW1_Value = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    }

    /* Turn on the Red Led */
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);

    /* Wait until the SW2 is pressed */
    while(SW2_Value != STD_LOW)
    {
        SW2_Value = Dio_ReadChannel(DioConf_SW2_CHANNEL_ID_INDEX);
    }

    /* Turn off the Red Led */
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
}

/************************************************************************************
* Test ID :TestCase6
* Description: Test for Flip and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press SW1(PF4) then the blue led(PF2) shall be flipped (OFF --> ON).
*                  2. Press SW2(PF0) then the blue led(PF2) shall be flipped (ON --> OFF).
*************************************************************************************/

void TestCase6(void)
{
    uint8 SW1_Value = STD_HIGH;
    uint8 SW2_Value = STD_HIGH;

    /* Wait until SW1 is pressed */
    while(SW1_Value != STD_LOW)
    {
        SW1_Value = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    }
    
    /* Flip the Blue Led */
    Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);
    
    /* Wait until SW2 button is pressed */
    while(SW2_Value != STD_LOW)
    {
        SW2_Value = Dio_ReadChannel(DioConf_SW2_CHANNEL_ID_INDEX);
    }
    
    /* Flip the Blue Led */
    Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);   
}


void GPIO_Pins_Init(void)
{
    /* Enable clock for PORTF and allow time for clock to start*/  
    volatile unsigned long delay = 0;
    SYSCTL_REGCGC2_REG |= 0x00000020;
    delay = SYSCTL_REGCGC2_REG;
    GPIO_PORTF_LOCK_REG    = 0x4C4F434B;    /* Unlock the GPIO_PORTF_CR_REG */
    GPIO_PORTF_CR_REG     |= (1<<0);        /* Enable changes on PF0 */
    GPIO_PORTF_AMSEL_REG  &= 0xE8;          /* Disable Analog on PF0, PF1, PF2 and PF4 */
    GPIO_PORTF_PCTL_REG   &= 0xFFF0F000;    /* Clear PMCx bits for PF0, PF1, PF2 and PF4 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG    = (GPIO_PORTF_DIR_REG & 0xE8) | 0x06;      /* Configure PF0 & PF1 as input pin and Configure PF1 & PF2 as output pins */
    GPIO_PORTF_AFSEL_REG  &= 0xE8;          /* Disable alternative function on PF0, PF1, PF2 and PF4 */
    GPIO_PORTF_PUR_REG    |= 0x11;          /* Enable pull-up on PF0 and PD4 */
    GPIO_PORTF_DEN_REG    |= 0x17;          /* Enable Digital I/O on PF0, PF1, PF2 and PF4 */
}

int main(void)
{
    /* Initailize PF0, PF1, PF2 and PF4 as GPIO pins */
    GPIO_Pins_Init();
  
    /* Initialize the Dio Driver */
    Dio_Init(&Dio_Configuration);
    while(1){
    /* Run the Fifth Test Case */
    //TestCase5();
    
    /* Run the Sixth Test Case */
    TestCase6();
		}
}
