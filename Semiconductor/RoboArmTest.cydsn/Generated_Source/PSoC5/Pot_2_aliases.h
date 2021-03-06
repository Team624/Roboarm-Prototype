/*******************************************************************************
* File Name: Pot_2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pot_2_ALIASES_H) /* Pins Pot_2_ALIASES_H */
#define CY_PINS_Pot_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pot_2_0			(Pot_2__0__PC)
#define Pot_2_0_INTR	((uint16)((uint16)0x0001u << Pot_2__0__SHIFT))

#define Pot_2_INTR_ALL	 ((uint16)(Pot_2_0_INTR))

#endif /* End Pins Pot_2_ALIASES_H */


/* [] END OF FILE */
