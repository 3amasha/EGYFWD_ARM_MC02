/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  DIO
 *
 *  Description:  Header file for TM4C123GH6PM Microcontroller - Dio Driver     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio_Cfg.h"
#include "Dio_Types.h"
#include "Std_Types.h"
#include "Common_Macros.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* function shall return the value of the specified DIO channel. */
Dio_LevelType Dio_ReadChannel( 
	Dio_ChannelType ChannelId 
);
/* function shall set the specified Level for the specified channel. */
void Dio_WriteChannel( 
 Dio_ChannelType ChannelId, 
 Dio_LevelType Level 
);
/* function shall return the level of all channels of that port.  */
Dio_PortLevelType Dio_ReadPort( 
 Dio_PortType PortId 
);
/* function shall set the specified value for the specified port.  */
void Dio_WritePort( 
 Dio_PortType PortId, 
 Dio_PortLevelType Level 
);
/* function shall initialize all global variables of the DIO module. */
void Dio_Init( 
 const Dio_ConfigType* ConfigPtr 
);
/* function shall read level of the channel and invert it, then write the inverted level to the channel. */
Dio_LevelType Dio_FlipChannel( 
 Dio_ChannelType ChannelId 
);
 
/**********************************************************************************************************************
 *  External Variables
 *********************************************************************************************************************/
 
/* Extern PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;



 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
