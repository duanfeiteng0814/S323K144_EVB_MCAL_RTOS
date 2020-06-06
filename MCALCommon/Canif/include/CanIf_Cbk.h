/**
*   @file    CanIf.h
*   @version 1.0.3
*
*   @brief   AUTOSAR CanIf - CanIf Cbk module interface
*   @details AUTOSAR CanIf Cbk module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.3
*   Build Version        : S32K14x_MCAL_1_0_3_RTM_ASR_REL_4_2_REV_0002_28-Feb-20
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2020 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CBK_VENDOR_ID                         43
#define CANIF_CBK_MODULE_ID                         60
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION          2
#define CANIF_CBK_AR_RELEASE_REVISION_VERSION       2
#define CANIF_CBK_SW_MAJOR_VERSION                  1
#define CANIF_CBK_SW_MINOR_VERSION                  0
#define CANIF_CBK_SW_PATCH_VERSION                  3
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CBK_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf_Cbk.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same module */
#if (CANIF_CBK_MODULE_ID != CANIF_TPYES_MODULE_ID)
#error "CanIf_Cbk.h and CanIf_Types.h have different module ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CBK_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CBK_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CBK_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf_Cbk.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_CBK_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_CBK_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_CBK_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf_Cbk.h and CanIf_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC (void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);

FUNC (void, CANIF_CODE) CanIf_RxIndication( const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr );

FUNC (void, CANIF_CODE) CanIf_ControllerBusOff(uint8 Controller);

FUNC (void, CANIF_CODE) CanIf_ControllerModeIndication( uint8 Controller, CanIf_ControllerModeType ControllerMode );
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
FUNC (void, CANIF_CODE) CanIf_CurrentIcomConfiguration( uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);
#endif
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
FUNC (Can_ReturnType, CANIF_CODE) CanIf_TriggerTransmit( PduIdType TxPduId,PduInfoType* PduInfoPtr );
#endif

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CBK_H */

/** @} */

