/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  DIO
 *
 *  Description:  Header File For Dio Module Data Types    
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Dio_Cfg.h" 

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
	/* Number of ports */
	#define  DIO_ACTIVE_PORTS      (6U)
 /*Type definition contain the numeric ID of a DIO channel used by the DIO APIs*/
 typedef enum
 {
	 Dio_Ch_0=0,
	 Dio_Ch_1,
	 Dio_Ch_2,
	 Dio_Ch_3,
	 Dio_Ch_4,
	 Dio_Ch_5,
	 Dio_Ch_6,
	 Dio_Ch_7
 }Dio_ChannelType;
 /*Type definition  contain the numeric ID of a DIO port used by the DIO APIs*/
 typedef enum
 {
	 Dio_PORTA=0,
	 Dio_PORTB,
   Dio_PORTC,
   Dio_PORTD,
   Dio_PORTE,
   Dio_PORTF	 
 }Dio_PortType;
 /*Type definition for the possible levels that a DIO channel can have (input or output)used by the DIO APIs  */
 typedef enum 
 {
	 STD_LOW=0x00, /* Physical state 0V */
	 STD_HIGH=0x01 /* Physical state 5V or 3.3V  */
 }Dio_LevelType;
 /*Type definition for the value of a DIO port used by the DIO APIs */
 typedef uint8 Dio_PortLevelType;
 
 
 /*----------- structure -----------*/
 
 /* Type for the definition of a channel group, which consists of several adjoining channels within a port. */
 typedef struct
 {
	 /* This element mask which defines the positions of the channel group. */
	 uint8 mask;
	 /* This element shall be the position of the Channel Group on the port, counted from the LSB.*/
	 uint8 offset;
	 /* This shall be the port on which the Channel group is defined. */
	 Dio_PortType PortIndex;
	 
 }Dio_ChannelGroupType;
 
 /*structure contains the IDs of configured channels*/
 typedef struct
 {
	 /* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
 }Dio_ConfigChannel;
 
 /* This structure contains all post-build configurable parameters of the DIO driver. 
    A pointer to this structure is passed to the DIO driver initialization function for configuration.*/
 typedef struct
 {
	 /* array of structure of type Dio_ConfigChannel, every struct contains IDs of configured channels */
	 Dio_ConfigChannel channels[DIO_CONFIGURED_CHANNLES];
	 
 }Dio_ConfigType;
 
 
 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
