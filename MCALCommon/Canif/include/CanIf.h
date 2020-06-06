/**
*   @file    CanIf.h
*   @version 1.0.3
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
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

#ifndef CANIF_H
#define CANIF_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf_Types.h"
#include "EcuM.h"
#include "CanIf_Cbk.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID                         43
#define CANIF_MODULE_ID                         60
#define CANIF_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_AR_RELEASE_MINOR_VERSION          2
#define CANIF_AR_RELEASE_REVISION_VERSION       2
#define CANIF_SW_MAJOR_VERSION                  1
#define CANIF_SW_MINOR_VERSION                  0
#define CANIF_SW_PATCH_VERSION                  3
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same module */
#if (CANIF_MODULE_ID != CANIF_TPYES_MODULE_ID)
#error "CanIf.h and CanIf_Types.h have different module ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif

/* Check if current file and CanIf_Cbk.h header file are of the same vendor */
#if (CANIF_VENDOR_ID != CANIF_CBK_VENDOR_ID)
#error "CanIf.h and CanIf_Cbk.h have different vendor ids"
#endif
/* Check if current file and CanIf_Cbk.h header file are of the same module */
#if (CANIF_MODULE_ID != CANIF_CBK_MODULE_ID)
#error "CanIf.h and CanIf_Cbk.h have different module ids"
#endif
/* Check if current file and CanIf_Cbk.h header file are of the same Autosar version */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_CBK_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_CBK_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf.h and CanIf_Cbk.h are different"
#endif
/* Check if current file and CanIf_Cbk.h header file are of the same software version */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_CBK_SW_MAJOR_VERSION) || \
     (CANIF_SW_MINOR_VERSION != CANIF_CBK_SW_MINOR_VERSION) || \
     (CANIF_SW_PATCH_VERSION != CANIF_CBK_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf.h and CanIf_Cbk.h are different"
#endif

/* Check if current file and EcuM.h header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CANIF_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf.h and EcuM.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define CANIF_WAKEUP_SUPPORT  (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
           
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
      FUNC (Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#endif

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_H */

/** @} */
