/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.c
 *       Module:  DIO
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Dio_Regs.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 /* Global pointer holding addres of configuration structure contains channels' IDs */
STATIC const Dio_ConfigChannel * Dio_PortChannels = NULL_PTR;
/* Global Flag for initialization status */
STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Dio_Init( const Dio_ConfigType* ConfigPtr )        
* \Description     : Initializes the module.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr ,Pointer to post-build configuration data                      
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Dio_Init( const Dio_ConfigType* ConfigPtr )
{
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ConfigPtr == NULL_PTR )
	{
		/* Do nothing */
	}
	else
	{
		/* Set the module state to initialized */  
		Dio_Status = DIO_INITIALIZED;
		/*
		 * point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Dio_PortChannels = ConfigPtr -> channels;/* address of the first Channels structure --> Channels[0] */
		
	}
	
}/* END Dio_Init fun */

/******************************************************************************
* \Syntax          : void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )        
* \Description     : Service to set a level of a channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                              
* \Parameters (in) : ChannelId ,ID of DIO channel 
*                    Level     ,Value to be written 
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	/* pointer holding GPIODATA reg for the port */
	volatile uint32 * Port_Ptr = NULL_PTR;
	/* flag for error */
	boolean error = FALSE;
	
	/* check if the Dio Module is not initialized */
	if (DIO_NOT_INITIALIZED == Dio_Status )
	{
		error = TRUE;/* if the module is not initialized */
	}
	else 
	{
		/* Do Nothing */
	}
	
	/* Check if the used channel is within the valid range
   * CONFIGURED_CHANNLES --> size of the array  & ChannelId --> index of the array 
	 */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId )
	{
		/* if index of array of structure  is greater than or egual to the size of the array */
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
		
	/* In-case there are no errors */
	if ( FALSE ==error )
	{
		/* make pointer Port_Ptr holds the GPIODATA reg for the port */
		switch (Dio_PortChannels[ChannelId].Port_Num)
		{
			case Dio_PORTA : Port_Ptr = &GPIO_PORTA_DATA_REG;
							 break;
			case Dio_PORTB : Port_Ptr = &GPIO_PORTB_DATA_REG;
							 break;
			case Dio_PORTC : Port_Ptr = &GPIO_PORTC_DATA_REG;
							 break;
			case Dio_PORTD : Port_Ptr = &GPIO_PORTD_DATA_REG;
							 break;
			case Dio_PORTE : Port_Ptr = &GPIO_PORTE_DATA_REG;
							 break;
			case Dio_PORTF : Port_Ptr = &GPIO_PORTF_DATA_REG;
							 break;
		}/* END switch */
		
		/* set a level of a channel. */
		if (Level == STD_HIGH)
		{
			SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}
		else if (Level == STD_LOW )
		{
			CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
	  } else { }
		
	}
	else
	{
		/* Do Nothing in case of error */
	}

}/* END Dio_WriteChannel fun*/	

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )        
* \Description     : Returns the value of the specified DIO channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                              
* \Parameters (in) : ChannelId ,ID of DIO channel
*                    
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType : STD_HIGH ,The physical level of the corresponding Pin is STD_HIGH 
*                                    STD_LOW  ,The physical level of the corresponding Pin is STD_LOW                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	/* pointer holding GPIODATA reg for the port */
	volatile uint32 * Port_Ptr = NULL_PTR;
	/* flag for error */
	boolean error = FALSE;
	/*Return value*/
	Dio_LevelType output =STD_LOW;
	
	/* check if the Dio Module is not initialized */
	if (DIO_NOT_INITIALIZED == Dio_Status )
	{
		error = TRUE;/* if the module is not initialized */
	}
	else 
	{
		/* Do Nothing */
	}
	
	/* Check if the used channel is within the valid range
   * CONFIGURED_CHANNLES --> size of the array  & ChannelId --> index of the array 
	 */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId )
	{
		/* if index of array of structure  is greater than or egual to the size of the array */
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	
	/* In-case there are no errors */
	if ( FALSE ==error )
	{
		/* make pointer Port_Ptr holds the GPIODATA reg for the port */
		switch (Dio_PortChannels[ChannelId].Port_Num)
		{
			case Dio_PORTA : Port_Ptr = &GPIO_PORTA_DATA_REG;
							 break;
			case Dio_PORTB : Port_Ptr = &GPIO_PORTB_DATA_REG;
							 break;
			case Dio_PORTC : Port_Ptr = &GPIO_PORTC_DATA_REG;
							 break;
			case Dio_PORTD : Port_Ptr = &GPIO_PORTD_DATA_REG;
							 break;
			case Dio_PORTE : Port_Ptr = &GPIO_PORTE_DATA_REG;
							 break;
			case Dio_PORTF : Port_Ptr = &GPIO_PORTF_DATA_REG;
							 break;
		}/* END switch */
		
		/* read a level of a channel. */
		if ( BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num) )
		{
			output =STD_HIGH;
		}
		else 
		{
			output=STD_LOW;
	  } 
		
	}
	else
	{
		/* Do Nothing in case of error */
	}
	
	return output;
	
}/* END Dio_ReadChannel fun*/

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )         
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return 
*                    the level of the channel after flip.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                              
* \Parameters (in) : ChannelId  ,ID of DIO channel 
*                    
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType : STD_HIGH ,The physical level of the corresponding Pin is STD_HIGH 
*                                    STD_LOW  ,The physical level of the corresponding Pin is STD_LOW                                  
*******************************************************************************/
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId ) 
{
	/* pointer holding GPIODATA reg for the port */
	volatile uint32 * Port_Ptr = NULL_PTR;
	/* flag for error */
	boolean error = FALSE;
	/*Return value*/
	Dio_LevelType output =STD_LOW;
	
	/* check if the Dio Module is not initialized */
	if (DIO_NOT_INITIALIZED == Dio_Status )
	{
		error = TRUE;/* if the module is not initialized */
	}
	else 
	{
		/* Do Nothing */
	}
	
	/* Check if the used channel is within the valid range
   * CONFIGURED_CHANNLES --> size of the array  & ChannelId --> index of the array 
	 */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId )
	{
		/* if index of array of structure  is greater than or egual to the size of the array */
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	
	/* In-case there are no errors */
	if ( FALSE ==error )
	{
		/* make pointer Port_Ptr holds the GPIODATA reg for the port */
		switch (Dio_PortChannels[ChannelId].Port_Num)
		{
			case Dio_PORTA : Port_Ptr = &GPIO_PORTA_DATA_REG;
							 break;
			case Dio_PORTB : Port_Ptr = &GPIO_PORTB_DATA_REG;
							 break;
			case Dio_PORTC : Port_Ptr = &GPIO_PORTC_DATA_REG;
							 break;
			case Dio_PORTD : Port_Ptr = &GPIO_PORTD_DATA_REG;
							 break;
			case Dio_PORTE : Port_Ptr = &GPIO_PORTE_DATA_REG;
							 break;
			case Dio_PORTF : Port_Ptr = &GPIO_PORTF_DATA_REG;
							 break;
		}/* END switch */
		
		/* flip a level of a channel. */
		if ( BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num) )
		{
			CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
			output=STD_LOW;
		}
		else 
		{
			SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
			output =STD_HIGH;
	  } 
		
	}
	else
	{
		/* Do Nothing in case of error */
	}
	
	return output;
	
}/* END Dio_FlipChannel fun*/

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )         
* \Description     : Returns the level of all channels of that port.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                              
* \Parameters (in) : PortId  ,ID of DIO Port
*                    
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType : Level of all channels of that port                                
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId ) 
{
	/* pointer holding GPIODATA reg for the port */
	volatile uint32 * Port_Ptr = NULL_PTR;
	/* flag for error */
	boolean error = FALSE;
	/*Return value*/
	Dio_PortLevelType output =0;
	
	/* check if the Dio Module is not initialized */
	if (DIO_NOT_INITIALIZED == Dio_Status )
	{
		error = TRUE;/* if the module is not initialized */
	}
	else 
	{
		/* Do Nothing */
	}
	
	/* Check if the used port is within the valid range
   * ACTIVE_PORTS --> 6 Ports  
	 */
	if (DIO_ACTIVE_PORTS <= PortId )
	{
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	
	/* In-case there are no errors */
	if ( FALSE ==error )
	{
		/* make pointer Port_Ptr holds the GPIODATA reg for the port */
		switch (PortId)
		{
			case Dio_PORTA : Port_Ptr = &GPIO_PORTA_DATA_REG;
							 break;
			case Dio_PORTB : Port_Ptr = &GPIO_PORTB_DATA_REG;
							 break;
			case Dio_PORTC : Port_Ptr = &GPIO_PORTC_DATA_REG;
							 break;
			case Dio_PORTD : Port_Ptr = &GPIO_PORTD_DATA_REG;
							 break;
			case Dio_PORTE : Port_Ptr = &GPIO_PORTE_DATA_REG;
							 break;
			case Dio_PORTF : Port_Ptr = &GPIO_PORTF_DATA_REG;
							 break;
		}/* END switch */
		
		output=*Port_Ptr;
		
	}
	else
	{
		/* Do Nothing in case of error */
	}
	
	return output;
	
}/* END Dio_ReadPort fun */

/******************************************************************************
* \Syntax          : void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )         
* \Description     : Service to set a value of the port.                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                              
* \Parameters (in) : PortId   : ID of DIO Port
*                    Level    : Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                               
*******************************************************************************/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level ) 
{
	/* pointer holding GPIODATA reg for the port */
	volatile uint32 * Port_Ptr = NULL_PTR;
	/* flag for error */
	boolean error = FALSE;
	
	/* check if the Dio Module is not initialized */
	if (DIO_NOT_INITIALIZED == Dio_Status )
	{
		error = TRUE;/* if the module is not initialized */
	}
	else 
	{
		/* Do Nothing */
	}
	
	/* Check if the used port is within the valid range
   * ACTIVE_PORTS --> 6 Ports 
	 */
	if (DIO_ACTIVE_PORTS <= PortId )
	{
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	
	/* In-case there are no errors */
	if ( FALSE ==error )
	{
		/* make pointer Port_Ptr holds the GPIODATA reg for the port */
		switch (PortId)
		{
			case Dio_PORTA : Port_Ptr = &GPIO_PORTA_DATA_REG;
							 break;
			case Dio_PORTB : Port_Ptr = &GPIO_PORTB_DATA_REG;
							 break;
			case Dio_PORTC : Port_Ptr = &GPIO_PORTC_DATA_REG;
							 break;
			case Dio_PORTD : Port_Ptr = &GPIO_PORTD_DATA_REG;
							 break;
			case Dio_PORTE : Port_Ptr = &GPIO_PORTE_DATA_REG;
							 break;
			case Dio_PORTF : Port_Ptr = &GPIO_PORTF_DATA_REG;
							 break;
		}/* END switch */
		
		*Port_Ptr=Level;
		
	}
	else
	{
		/* Do Nothing in case of error */
	}
	
}/* END Dio_WritePort fun */




/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
