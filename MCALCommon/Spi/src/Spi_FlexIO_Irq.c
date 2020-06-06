/**
*   @file    Spi_FLEXIO_Irq.c
*   @implements     Spi_FLEXIO_Irq.c_Artifact
*   @version 1.0.3
*
*   @brief   AUTOSAR Spi- Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI,FLEXIO
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

#ifdef __cplusplus
extern "C"
{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_FLEXIO_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_FLEXIO_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_FLEXIO_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are 
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_FLEXIO_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function
* and any type other than an integral type.
* This violation can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific features.
*
* @section Spi_FLEXIO_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"

#if (STD_ON == SPI_ENABLE_FLEXIO)
    #include "Spi_FlexIO.h"
#endif
/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_MODULE_ID_IRQ_FLEXIO_C                      83
#define SPI_VENDOR_ID_IRQ_FLEXIO_C                      43
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_IRQ_FLEXIO_C       4
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_IRQ_FLEXIO_C       2
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_IRQ_FLEXIO_C    2
#define SPI_SW_MAJOR_VERSION_IRQ_FLEXIO_C               1
#define SPI_SW_MINOR_VERSION_IRQ_FLEXIO_C               0
#define SPI_SW_PATCH_VERSION_IRQ_FLEXIO_C               3

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_FLEXIO_C != SPI_VENDOR_ID)
    #error "Spi_FlexIO_Irq.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_FLEXIO_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_IRQ_FLEXIO_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_IRQ_FLEXIO_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_FlexIO_Irq.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_IRQ_FLEXIO_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_IRQ_FLEXIO_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_IRQ_FLEXIO_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_FlexIO_Irq.c and Spi.h are different"
#endif

#if (STD_ON == SPI_ENABLE_FLEXIO)
/* Check if this header file and Spi_FlexIO.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_FLEXIO_C != SPI_FLEXIO_VENDOR_ID)
    #error "Spi_FlexIO_Irq.c and Spi_FlexIO.h have different vendor ids"
#endif

#if (( SPI_AR_RELEASE_MAJOR_VERSION_IRQ_FLEXIO_C    != SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     ( SPI_AR_RELEASE_MINOR_VERSION_IRQ_FLEXIO_C    != SPI_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     ( SPI_AR_RELEASE_REVISION_VERSION_IRQ_FLEXIO_C != SPI_FLEXIO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.h and Spi_FlexIO_Irq.c are different"
#endif

#if (( SPI_SW_MAJOR_VERSION_IRQ_FLEXIO_C != SPI_FLEXIO_SW_MAJOR_VERSION) || \
     ( SPI_SW_MINOR_VERSION_IRQ_FLEXIO_C != SPI_FLEXIO_SW_MINOR_VERSION) || \
     ( SPI_SW_PATCH_VERSION_IRQ_FLEXIO_C != SPI_FLEXIO_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_FlexIO_Irq.c and Spi_FlexIO.h are different"
#endif


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FLEXIO_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the FLEXIO 0. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for FLEXIO 0
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter FLEXIO_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #if (SPI_DMA_USED == STD_ON)
        #ifdef FLEXIOSPI_0_USED
            #if (FLEXIOSPI_0_USED == STD_ON)
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_0(void);
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_0(void);
            #endif
        #endif
        #ifdef FLEXIOSPI_1_USED
            #if (FLEXIOSPI_1_USED == STD_ON)
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_1(void);
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_1(void);
            #endif
        #endif
        #ifdef FLEXIOSPI_2_USED
            #if (FLEXIOSPI_2_USED == STD_ON)
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_2(void);
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_2(void);
            #endif
        #endif
        #ifdef FLEXIOSPI_3_USED
            #if (FLEXIOSPI_3_USED == STD_ON)
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_3(void);
                FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_3(void);
            #endif
        #endif
    #endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
#ifdef FLEXIOSPI_0_USED
#if (FLEXIOSPI_0_USED == STD_ON)
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_0(void)
{
    Spi_FlexIO_IsrDmaRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_0_HWUNIT));
}
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_0(void)
{
    Spi_FlexIO_IsrDmaTx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_0_HWUNIT));
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the FlexIO 1. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for FlexIO 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter FLEXIOSPI_1_USED shall be STD_ON.
*
*/
/*================================================================================================*/
#ifdef FLEXIOSPI_1_USED
#if (FLEXIOSPI_1_USED == STD_ON)
    /*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_1(void)
{
    Spi_FlexIO_IsrDmaRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_1_HWUNIT));
}
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_1(void)
{
    Spi_FlexIO_IsrDmaTx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_1_HWUNIT));
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the FlexIO 2. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for FlexIO 2
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter FLEXIOSPI_2_USED shall be STD_ON.
*
*/
/*================================================================================================*/
#ifdef FLEXIOSPI_2_USED
#if (FLEXIOSPI_2_USED == STD_ON)
    /*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_2(void)
{
    Spi_FlexIO_IsrDmaRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_2_HWUNIT));
}
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_2(void)
{
    Spi_FlexIO_IsrDmaTx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_2_HWUNIT));
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the FlexIO 3. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for FlexIO 3
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter FLEXIOSPI_3_USED shall be STD_ON.
*
*/
/*================================================================================================*/
#ifdef FLEXIOSPI_3_USED
#if (FLEXIOSPI_3_USED == STD_ON)
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrRxDma_Spi_3(void)
{
    Spi_FlexIO_IsrDmaRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_3_OFFSET));
}
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_8 All declarations and definitions of objects or functions
* at file scope shall
*/
FUNC (void, SPI_CODE) Spi_FlexIO_IsrTxDma_Spi_3(void)
{
    Spi_FlexIO_IsrDmaTx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_3_OFFSET));
}
#endif
#endif
#endif /*SPI_DMA_USED*/
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the FlexIO 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for FlexIO 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter FLEXIO_0_SPI_1_USED shall be STD_ON.
*
*/
#endif /*SPI_LEVEL_DELIVERED*/
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_FLEXIO_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FLEXIO_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 #endif /* SPI_ENABLE_FLEXIO == STD_ON */

#ifdef __cplusplus
}
#endif /*SPI_FLEXIO_IRQ_C*/

/** @} */
