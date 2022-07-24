/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Cfg.h
 *       Module:  DIO
 *
 *  Description:  Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver    
 *  
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/*
 * Number of the configured Dio Channels and configured Ports
 */
#define DIO_CONFIGURED_CHANNLES              (1U)

/*----------------------CHANNEL INDEX ----------------------------------------*/
/*
 *  Channel Index in the array of structures in Dio_PBcfg.c 
 */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00

/*----------------------CHANNEL NUMBER ---------------------------------------*/  
/*
 *  DIO Configured Port ID's
 */
#define DioConf_LED1_PORT_NUM                 Dio_PORTF /* PORTF */

/*
 *  DIO Configured Channel ID's 
 */
#define DioConf_LED1_CHANNEL_NUM              Dio_Ch_1 /* Pin 1 in PORTF */


#endif  /* DIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Cfg.h
 *********************************************************************************************************************/
