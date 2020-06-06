/**
*   @file    Wdg_Wdog.c
*
*   @version 1.0.3
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (WDOG) functions
*   @details Contains functions for accessing WDOG from the WDG driver perspective
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Wdog
*   Dependencies         : none
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Wdog_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_Wdog_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section [global]
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section Wdg_Wdog_c_REF_4
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to the
*          pointer arithmetic used to write/ read the data to/from the registers
* @section Wdg_Wdog_c_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          External linkage is required.
* @section Wdg_Wdog_c_REF_6
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer
*          type and an integral type. This violation is due to the pointer arithmetic used to 
*          write/ read the data to/from the registers.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Wdg_Wdog_c_REF_7
*          Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
*          This violation is because of complex statement
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Wdg_Wdog.c    
*/

#include "Wdg_IPW_Types.h"
#include "Wdg_Wdog.h"
#include "Reg_eSys_Wdog.h"
#include "Reg_eSys_Wdog_defines.h"
#include "Mcal.h"
#include "StdRegMacros.h"
#include "SchM_Wdg.h"

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Wdog.c
*/
#define WDG_WDOG_VENDOR_ID_C                     43

#define WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C      4

#define WDG_WDOG_AR_RELEASE_MINOR_VERSION_C      2

#define WDG_WDOG_AR_RELEASE_REVISION_VERSION_C   2
#define WDG_WDOG_SW_MAJOR_VERSION_C              1
#define WDG_WDOG_SW_MINOR_VERSION_C              0
#define WDG_WDOG_SW_PATCH_VERSION_C              3
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Wdog header file are of the same vendor */
#if (WDG_WDOG_VENDOR_ID_C != WDG_WDOG_VENDOR_ID)
    #error "Wdg_Wdog.c and Wdg_Wdog.h have different vendor ids"
#endif
/* Check if current file and Wdg_Wdog header file are of the same Autosar version */
#if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C    != WDG_WDOG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C    != WDG_WDOG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_REVISION_VERSION_C != WDG_WDOG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Wdog.c and Wdg_Wdog.h are different"
#endif
/* Check if current file and WDOG header file are of the same Software version */
#if ((WDG_WDOG_SW_MAJOR_VERSION_C != WDG_WDOG_SW_MAJOR_VERSION) || \
     (WDG_WDOG_SW_MINOR_VERSION_C != WDG_WDOG_SW_MINOR_VERSION) || \
     (WDG_WDOG_SW_PATCH_VERSION_C != WDG_WDOG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_Wdog.c and Wdg_Wdog.h are different"
#endif

/* Check if current file and WDOG register header file are of the same vendor */
#if (WDG_WDOG_VENDOR_ID_C != REG_ESYS_WDOG_VENDOR_ID)
    #error "Wdg_Wdog.c and Reg_eSys_Wdog.h have different vendor ids"
#endif

/* Check if source file and WDOG register header file are of the same Autosar version */
#if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_WDOG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_WDOG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_WDOG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Wdog.c and Reg_eSys_Wdog.h are different"
#endif

/* Check if source file and WDOG register header file are of the same Software version */
#if ((WDG_WDOG_SW_MAJOR_VERSION_C != REG_ESYS_WDOG_SW_MAJOR_VERSION) || \
     (WDG_WDOG_SW_MINOR_VERSION_C != REG_ESYS_WDOG_SW_MINOR_VERSION) || \
     (WDG_WDOG_SW_PATCH_VERSION_C != REG_ESYS_WDOG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_Wdog.c and Reg_eSys_Wdog.h are different"
#endif

/* Check if current file and Reg_eSys_Wdog_defines header file are of the same vendor */
#if (WDG_WDOG_VENDOR_ID_C != REG_ESYS_WDOG_DEFINES_VENDOR_ID)
    #error "Wdg_Wdog.c and Reg_eSys_Wdog_defines.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_Wdog_defines header file are of the same Autosar version */
#if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_WDOG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_WDOG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_WDOG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Wdog.c and Reg_eSys_Wdog_defines.h are different"
#endif

/* Check if source file and Reg_eSys_Wdog_defines header file are of the same Software version */
#if ((WDG_WDOG_SW_MAJOR_VERSION_C != REG_ESYS_WDOG_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_WDOG_SW_MINOR_VERSION_C != REG_ESYS_WDOG_DEFINES_SW_MINOR_VERSION) || \
     (WDG_WDOG_SW_PATCH_VERSION_C != REG_ESYS_WDOG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_Wdog.c and Reg_eSys_Wdog_defines.h are different"
#endif
/* Check if current file and Wdg_IPW_Types header file are of the same vendor */
#if (WDG_WDOG_VENDOR_ID_C != WDG_IPW_TYPES_VENDOR_ID)
    #error "Wdg_Wdog.c and Wdg_IPW_Types.h have different vendor ids"
#endif

/* Check if source file and Wdg_IPW_Types header file are of the same Autosar version */
#if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_WDOG_AR_RELEASE_REVISION_VERSION_C != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Wdog.c and Wdg_IPW_Types.h are different"
#endif

/* Check if source file and Wdg_IPW_Types header file are of the same Software version */
#if ((WDG_WDOG_SW_MAJOR_VERSION_C != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_WDOG_SW_MINOR_VERSION_C != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_WDOG_SW_PATCH_VERSION_C != WDG_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_Wdog.c and Wdg_IPW_Types.h are different"
#endif

/* Check if current file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Wdg_Wdog.c and StdRegMacros.h are different"
    #endif
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_WDOG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Wdg_Wdog.c and Mcal.h are different"
    #endif
#endif

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( WDG_WDOG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( WDG_WDOG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
         )
         #error "AutoSar Version Numbers of Wdg_Wdog.c and Dem.h are different"
     #endif
 #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/



/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"



#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


#define WDG_START_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"
/** @violates @ref Wdg_Wdog_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *                   functions at file scope shall have internal linkage unless external linkage is required. 
 **/
CONST(uint32, WDG_CONST) WDOG_aBASE_ADDR32[] = 
{
#ifdef WDOG_0_BASEADDR
    WDOG_0_BASEADDR
#else
#ifdef WDOG_BASEADDR
    WDOG_BASEADDR
#else
    ((uint32)0x00000000UL)
#endif
#endif  
#ifdef WDOG_1_BASEADDR
    ,WDOG_1_BASEADDR
#else
    ,((uint32)0x00000000UL)
#endif
#ifdef WDOG_2_BASEADDR
    ,WDOG_2_BASEADDR
#else
    ,((uint32)0x00000000UL)
#endif
#ifdef WDOG_3_BASEADDR
    ,WDOG_3_BASEADDR
#else
    ,((uint32)0x00000000UL)
#endif
};
#define WDG_STOP_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"


#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
*   @brief   This function initializes the hardware of WDG module.
*   @details Sets up the values such as timeout value
*
*   @param[in]      Wdog_pConfigPtr      Pointer to configuration set.
*   @param[in]      Wdg_Instance        Harwdware WDOG instance.
* 
*   @return uint32      The value in ticks that need to be set up for the timer
*
*/
FUNC(uint32, WDG_CODE) Wdg_Wdog_Init(P2CONST(Wdg_Wdog_ConfigType, AUTOMATIC, WDG_APPL_CONST) Wdog_pConfigPtr,
                                     CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                    )
{
    VAR(uint32, AUTOMATIC) gptPeriodWdgTicks = WDG_TICKS_INIT_VAL_U16;
    VAR(volatile uint32, AUTOMATIC) u32Timeout;

    SuspendAllInterrupts();
    /* Unlock the possible soft lock condition   */
    /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(WDOG_CNT_ADDR32(Wdg_Instance), WDOG_UNLOCK_SEQ_U32);

    /* calculate timeout and window period in ticks */
    if (Wdog_pConfigPtr->Wdog_bPrescalerEn)
    {
        /* Set Timer-out register */
        /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(WDOG_TOVAL_ADDR32(Wdg_Instance), (Wdog_pConfigPtr->Wdog_u32Timeout/WDG_PRESCALER_VALUE_U16));

        /* Set Window register */
        /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(WDOG_WIN_ADDR32(Wdg_Instance), (Wdog_pConfigPtr->Wdog_u32Window/WDG_PRESCALER_VALUE_U16));
    }
    else
    {
        /* Set Timer-out register */
        /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(WDOG_TOVAL_ADDR32(Wdg_Instance), (Wdog_pConfigPtr->Wdog_u32Timeout));

        /* Set Window register */
        /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(WDOG_WIN_ADDR32(Wdg_Instance), (Wdog_pConfigPtr->Wdog_u32Window));
    }

    u32Timeout = (uint32)WDG_RECONFIGURATION_TIMEOUT;

    /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(WDOG_CS_ADDR32(Wdg_Instance),(Wdog_pConfigPtr->Wdog_u32Config));

    /* Check if reconfiguration was done in the timeout */
    /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_7 Violates MISRA 2004 Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. */
    while (((REG_READ32(WDOG_CS_ADDR32(Wdg_Instance)) & WDOG_REC_SUCCESS_U32) != WDOG_REC_SUCCESS_U32) && (u32Timeout > 0UL))
    {
        u32Timeout--;
    }

    if (0UL == u32Timeout)
    {
    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if((uint32)STD_ON == Wdg_E_Timeout_Expired.state)
        {
 
            Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Timeout_Expired.id, DEM_EVENT_STATUS_FAILED);
        }
    #endif
    }

    ResumeAllInterrupts();

    gptPeriodWdgTicks = (uint32)(Wdog_pConfigPtr->Wdog_u32Window + (uint32)((Wdog_pConfigPtr->Wdog_u32Timeout - Wdog_pConfigPtr->Wdog_u32Window)>>1));

    return gptPeriodWdgTicks;
}


/**
*   @brief   This function triggers the watchdog hardware.
*   @details Writes the trigger sequence on the hardware
*
*   @param[in]      Wdg_Instance   Harwdware WDOG instance.
* 
* 
*   @return void
*  
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
* 
*/
FUNC(void, WDG_CODE) Wdg_Wdog_Trigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    SuspendAllInterrupts();
    /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(WDOG_CNT_ADDR32(Wdg_Instance), WDOG_TRIGGER_SEQUENCE_U32);
    ResumeAllInterrupts();
}


/**
*   @brief   The function checks the consistence between the configuration and the hardware.
*   @details Verifies if the given configuration set is within hardware limits
* 
*
*   @return             Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_Wdog_CheckHwSettings(P2CONST(Wdg_Wdog_ConfigType, AUTOMATIC, WDG_APPL_CONST) Wdog_pConfigPtr,
                                                        CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                       )
{
    VAR(Std_ReturnType, AUTOMATIC) response = (Std_ReturnType)E_OK;

    (void)Wdg_Instance;
    /* Returns error if the configuration pointer is NULL*/
    if (NULL_PTR == Wdog_pConfigPtr)
    {
        response = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Returns error if the timeout value is grater that the minimum timeout value supported by hardware*/
        if (Wdog_pConfigPtr->Wdog_u32Timeout < WDOG_MIN_VALUE_TIMEOUT_U32)
        {
            response = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Return error if the value of the window frame is grater that the timeout - no trigger can occur*/
            if (WDOG_TRIGGER_MODE_WINDOW_U32 == (Wdog_pConfigPtr->Wdog_u32Config & WDOG_TRIGGER_MODE_WINDOW_U32))
            {
                if (Wdog_pConfigPtr->Wdog_u32Timeout < Wdog_pConfigPtr->Wdog_u32Window)
                {
                    response = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }
    return response;
}

#ifdef WDG_VALIDATE_CONFIG_UPDATE        
#if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)
/**
*   @brief   The function checks if the WDG configuration update is allowed by hardware
*   @details V
* 
*
*   @return             Std_ReturnType
*   @retval E_OK        The config update is allowed by hardware
*
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_Wdog_ValidateConfigUpdate(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) response = (Std_ReturnType)E_OK;

    /* Returns error if the WDG configuration update is not allowed by hardware */
    /* @violates @ref Wdg_Wdog_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Wdog_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    if (WDOG_UPDATE_DISABLED_U32 == (REG_READ32(WDOG_CS_ADDR32(Wdg_Instance)) & WDOG_UPDATE_ENABLED_U32))
    {
        response = (Std_ReturnType)E_NOT_OK;
    }

    return response;
}

#endif
#endif
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Wdog_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @violates @ref Wdg_Wdog_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*/
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
