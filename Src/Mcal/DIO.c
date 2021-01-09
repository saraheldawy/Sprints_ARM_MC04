/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.c
 *       Module:  DIO
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                    
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 PortType = ChannelId / 8;
    uint8 ChannelNum = ChannelId % 8;
    return GPIO_DATA(ChannelNum, PortType);
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)                                      
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId, Dio_LevelType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 PortType = ChannelId / 8;
    uint8 ChannelNum = ChannelId % 8;
    GPIO_DATA(ChannelNum, PortType) = Level;
}

/******************************************************************************
* \Syntax          : void Dio_ReadPort(Dio_PortType PortId)                                    
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_PortType PortId                     
* \Parameters (out): Dio_PortLevelType                                                     
* \Return value:   : Dio_PortLevelType
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return GPIO_PORT_DATA(PortId);
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)                                      
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_PortType PortId, Dio_PortLevelType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    GPIO_PORT_DATA(PortId) = Level;
}

/******************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelId)                                      
* \Description     : 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                     
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint8 PortType = ChannelId / 8;
    uint8 ChannelNum = ChannelId % 8;
    Dio_LevelType Level = GPIO_DATA(ChannelNum, PortType);
    return Level ^= Level;
}





/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/ 