/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_PCcfg.c
 *       Module:  DIO
 *
 *  Description:  Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"



/* PB structure used with Dio_Init API */
const Dio_ConfigType Dio_Configuration = {
  /*------------------------------------------------------------------------------*/
	/* channels[ ]     Port_Num                      Ch_Num                         */
	/*------------------------------------------------------------------------------*/
  /*index=0 */       DioConf_LED1_PORT_NUM,        DioConf_LED1_CHANNEL_NUM ,
	
	
};



/**********************************************************************************************************************
 *  END OF FILE: Dio_PCcfg.c
 *********************************************************************************************************************/
