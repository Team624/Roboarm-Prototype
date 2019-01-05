/*******************************************************************************
* File Name: Pot_Values.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Pot_Values_H)
#define CY_AMUX_Pot_Values_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void Pot_Values_Start(void) ;
#define Pot_Values_Init() Pot_Values_Start()
void Pot_Values_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Pot_Values_Stop(void); */
/* void Pot_Values_Select(uint8 channel); */
/* void Pot_Values_Connect(uint8 channel); */
/* void Pot_Values_Disconnect(uint8 channel); */
/* void Pot_Values_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Pot_Values_CHANNELS  3u
#define Pot_Values_MUXTYPE   1
#define Pot_Values_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Pot_Values_NULL_CHANNEL 0xFFu
#define Pot_Values_MUX_SINGLE   1
#define Pot_Values_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Pot_Values_MUXTYPE == Pot_Values_MUX_SINGLE
# if !Pot_Values_ATMOSTONE
#  define Pot_Values_Connect(channel) Pot_Values_Set(channel)
# endif
# define Pot_Values_Disconnect(channel) Pot_Values_Unset(channel)
#else
# if !Pot_Values_ATMOSTONE
void Pot_Values_Connect(uint8 channel) ;
# endif
void Pot_Values_Disconnect(uint8 channel) ;
#endif

#if Pot_Values_ATMOSTONE
# define Pot_Values_Stop() Pot_Values_DisconnectAll()
# define Pot_Values_Select(channel) Pot_Values_FastSelect(channel)
void Pot_Values_DisconnectAll(void) ;
#else
# define Pot_Values_Stop() Pot_Values_Start()
void Pot_Values_Select(uint8 channel) ;
# define Pot_Values_DisconnectAll() Pot_Values_Start()
#endif

#endif /* CY_AMUX_Pot_Values_H */


/* [] END OF FILE */
