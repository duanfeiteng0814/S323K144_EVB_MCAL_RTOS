/**
*   @file           Eth_GeneralTypes.h
*   @implements     Eth_GeneralTypes.h_Artifact
*   @version 1.0.3
*   @brief   AUTOSAR Base driver type definitions header file
*   @details Definitions of types for the Ethernet driver
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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

#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_GeneralTypes_h_REF_1
*      Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
*      character significance and case sensitivity are supported for external identifiers.
*      The used compilers use more than 31 chars for identifiers
* @section Eth_GeneralTypes_h_REF_2
*     Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*     contents of a header file being included twice. 
*     This is not a violation since all header files are protected against multiple inclusions
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
* @section [global]
*     Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and 
*     functions shall not be reused. The driver needs to use defines starting with letter E.

*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
 * @violates @ref Eth_GeneralTypes_h_REF_2 precautions to prevent the
 * contents of a header file being included twice  */
#include "ComStack_Types.h" /* Mandatory include - see the SWS */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          The Ethernet driver state.
* @details        A variable of this type holds the state of the Ethernet driver
*                 module. The driver is at the ETH_STATE_UNINIT at the beginning
*                 until the Eth_Init() function is called. The state remains
*                 equal to the ETH_STATE_INIT until the Eth_ControllerInit()
*                 function is called. Then the state is ETH_STATE_ACTIVE.
* @implements     Eth_StateType_enumeration
*/
typedef enum
{
    ETH_STATE_UNINIT = 0, /**< The driver has not been initialized yet */
     ETH_STATE_INIT        /**< The driver has not been configured and
                               the controller was configured */
 } Eth_StateType;

/**
* @brief          The Ethernet controller mode.
* @details        This type is used to store the information whether the
*                 Ethernet controller is stopped or running.
* @implements     Eth_ModeType_enumeration
*/
typedef enum
{
    ETH_MODE_DOWN = 0,    /**< Controller is shut down */
    ETH_MODE_ACTIVE       /**< Controller is active */
}  Eth_ModeType;

/**
* @brief          The Ethernet reception status
* @details        This status is returned by the @c Eth_Receive() function to indicate
*                 whether any frame has been received and if yes, whether there is any
*                 frame still waiting in the queue (for another @c Eth_Receive() call).
* @implements     Eth_RxStatusType_enumeration
*/
 typedef enum
{
    ETH_RECEIVED = 0,   /**< A frame has been received and there are no more frames in the queue */
    ETH_NOT_RECEIVED,   /**< No frames received */
    ETH_RECEIVED_MORE_DATA_AVAILABLE /**< A frame received and at least another one in the queue detected */
} Eth_RxStatusType;
 /**
* @brief          Action type for PHY address filtering
* @details        The Enumeration type describes the action to be taken
*                 for the MAC address given in *PhysAddrPtr
* @implements     Eth_FilterActionType_enumeration
*/
typedef enum
{
    ETH_ADD_TO_FILTER = 0,    /**< Add address to the filter */
    ETH_REMOVE_FROM_FILTER    /**< Remove address */
} Eth_FilterActionType;

  

 /**
* @brief          The Ethernet specific return type
* @details        This return type informs about the function success or failure status.
* @implements     Eth_ReturnType_enumeration
*/
typedef enum
{
    ETH_OK = 0,         /**< Success */
    ETH_E_NOT_OK,       /**< General failure */
    ETH_E_NO_ACCESS     /**< Ethernet hardware access failure */
}  Eth_ReturnType;
 
/**
* @brief          The Ethernet quality of timestamp type
* @details        Depending on the HW, quality information regarding the evaluated time stamp 
*                 might be supported. If not supported, the value shall be always Valid. For 
*                 Uncertain and Invalid values, the upper layer shall discard the time stamp.
* @implements     Eth_TimeStampQualType_enumeration
*/
typedef enum
{
    ETH_VALID = 0,         /**< Success */
    ETH_INVALID,       /**< General failure */
    ETH_UNCERTAIN     /**< Ethernet hardware access failure */
}  Eth_TimeStampQualType;

/**
* @brief  Status supervision used for Development Error Detection. The state shall be available for debugging.
*/
typedef enum
{
    /**< @brief The Eth Switch Driver is not yet configured. */
    ETHSWT_STATE_UNINIT = (uint8)0x0U,
    /**< @brief The Eth Switch Driver is configured */
    ETHSWT_STATE_INIT   = (uint8)0x1U,
    /**< @brief The Eth Switch driver is active. */
    ETHSWT_STATE_ACTIVE = (uint8)0x2U

} EthSwt_StateType;

/**
* @brief  MAC learning type enumeration.
*/
typedef enum
{
    /**< @brief If hardware learning disabled, the switch must not learn new MAC addresses */
    ETHSWT_MACLEARNING_HWDISABLED  = (uint8)0x0U,
    /**< @brief If hardware learning enabled, the switch learns new MAC addresses */
    ETHSWT_MACLEARNING_HWENABLED   = (uint8)0x1U,
    /**< @brief If software learning enabled, the hardware learning is disabled and the switch forwards packets 
                with an unknown source address to a host CPU */
    ETHSWT_MACLEARNING_SWENABLED   = (uint8)0x2U
    
} EthSwt_MacLearningType;

/**
* @brief It shall be possible to set and get the state (enable / disable) of the ehternet switch port.
*/
typedef enum
{
    /**< @brief port mirroring disabled. */
    PORT_MIRROR_DISABLED = (uint8)0x0U,
    /**< @brief port mirroring enabled. */
    PORT_MIRROR_ENABLED  = (uint8)0x1U
    
} EthSwt_PortMirrorStateType;


/**
* @brief This type defines the Ethernet link state. The link state changes after an Ethernet cable gets plugged in and the transceivers on both ends negotiated the transmission parameters (i.e. baud rate and duplex mode)
*/
typedef enum
{
    /**< @brief No physical Ethernet connection established. */
    ETHTRCV_LINK_STATE_DOWN = (uint8)0x0U,
    /**< @brief Physical Ethernet connection established. */
    ETHTRCV_LINK_STATE_ACTIVE  = (uint8)0x1U
    
} EthTrcv_LinkStateType;

/**
* @brief This type defines the Ethernet link state. The link state changes after an Ethernet cable gets plugged in and the transceivers on both ends negotiated the transmission parameters (i.e. baud rate and duplex mode)
*/
typedef enum
{
    /**< @brief Driver is not yet configured */
    ETHTRCV_STATE_UNINIT = (uint8)0x0U,
    /**< @brief Driver is configured. */
    ETHTRCV_STATE_INIT  = (uint8)0x1U
    
} EthTrcv_StateType;

/**
* @brief This type defines the Ethernet baud rate. The baud rate gets either negotiated between the connected transceivers or has to be configured.
*/
typedef enum
{
    /**< @brief 10MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_10MBIT = (uint8)0x0U,
    /**< @brief 100MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_100MBIT,
    /**< @brief 1000MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_1000MBIT

} EthTrcv_BaudRateType;

/**
* @brief This type defines the Ethernet duplex mode. The duplex mode gets either negotiated between the connected transceivers or has to be configured.
*/
typedef enum
{
    /**< @brief Half duplex Ethernet connection */
    ETHTRCV_DUPLEX_MODE_HALF = (uint8)0x0U,
    /**< @brief Full duplex Ethernet connection */
    ETHTRCV_DUPLEX_MODE_FULL  = (uint8)0x1U
    
} EthTrcv_DuplexModeType;

/**
* @brief This type controls the transceiver wake up modes and/or clears the wake-up reason.
*/
typedef enum
{
    /**< @brief Transceiver wake up disabled */
    ETHTRCV_WUM_DISABLE = (uint8)0x0U,
    /**< @brief Transceiver wake up enabled */
    ETHTRCV_WUM_ENABLE,
    /**< @brief Transceiver wake up reason cleared. */
    ETHTRCV_WUM_CLEAR
    
} EthTrcv_WakeupModeType;

/**
* @brief This type defines the transceiver wake up reasons.
*/
typedef enum
{
    /**< @brief No wake up reason detected. */
    ETHTRCV_WUR_NONE = (uint8)0x0U,
    /**< @brief General wake up detected, no distinct reason supported by hardware. */
    ETHTRCV_WUR_GENERAL  = (uint8)0x1U,
    /**< @brief Bus wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_BUS  = (uint8)0x2U,
    /**< @brief Internal wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_INTERNAL  = (uint8)0x3U,
    /**< @brief Reset wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_RESET  = (uint8)0x4U,
    /**< @brief Power on wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_POWER_ON  = (uint8)0x5U,
    /**< @brief Pin wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_PIN  = (uint8)0x6U,
    /**< @brief System error wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_SYSERR  = (uint8)0x7U
    
} EthTrcv_WakeupReasonType;

/**
* @brief Describes the possible PHY test modes
*/
typedef enum
{
    /**< @brief normal operation */
    ETHTRCV_PHYTESTMODE_NONE = (uint8)0x0U,
    /**< @brief test transmitter droop */
    ETHTRCV_PHYTESTMODE_1  = (uint8)0x1U,
    /**< @brief test master timing jitter */
    ETHTRCV_PHYTESTMODE_2  = (uint8)0x2U,
    /**< @brief test slave timing jitter */
    ETHTRCV_PHYTESTMODE_3  = (uint8)0x3U,
    /**< @brief test transmitter distortion */
    ETHTRCV_PHYTESTMODE_4  = (uint8)0x4U,
    /**< @brief test power spectral density (PSD) mask */
    ETHTRCV_PHYTESTMODE_5  = (uint8)0x5U
    
} EthTrcv_PhyTestModeType;

/**
* @brief Describes the possible PHY loopback modes
*/
typedef enum
{
    /**< @brief normal operation */
    ETHTRCV_PHYLOOPBACK_NONE = (uint8)0x0U,
    /**< @brief internal loopback */
    ETHTRCV_PHYLOOPBACK_INTERNAL  = (uint8)0x1U,
    /**< @brief external loopback */
    ETHTRCV_PHYLOOPBACK_EXTERNAL  = (uint8)0x2U,
    /**< @brief remote loopback */
    ETHTRCV_PHYLOOPBACK_REMOTE  = (uint8)0x3U
    
} EthTrcv_PhyLoopbackModeType;

/**
* @brief Describes the possible PHY transmit modes
*/
typedef enum
{
    /**< @brief normal operation */
    ETHTRCV_PHYTXMODE_NORMAL = (uint8)0x0U,
    /**< @brief transmitter disabled */
    ETHTRCV_PHYTXMODE_TX_OFF  = (uint8)0x1U,
    /**< @brief scrambler disabled */
    ETHTRCV_PHYTXMODE_SCRAMBLER_OFF  = (uint8)0x2U
    
} EthTrcv_PhyTxModeType;

/**
* @brief Describes the results of the cable diagnostics.
*/
typedef enum
{
    /**< @brief Cable diagnostic ok */
    ETHTRCV_CABLEDIAG_OK = (uint8)0x0U,
    /**< @brief Cable diagnostic failed */
    ETHTRCV_CABLEDIAG_ERROR  = (uint8)0x1U,
    /**< @brief Short circuit detected */
    ETHTRCV_CABLEDIAG_SHORT  = (uint8)0x2U,
    /**< @brief Open circuit detected */
    ETHTRCV_CABLEDIAG_OPEN  = (uint8)0x3U
    
} EthTrcv_CableDiagResultType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief         Frame Id type.
*/
typedef uint16 Eth_FrameIdType;

/**
* @brief         Frame type.
* @details       This type is used to pass the value of type or length field in the
*                Ethernet frame header. It is 16 bits long unsigned integer.
*                - Values less than or equal to 1500 represent the length.
*                - Values grater than 1500 represent the type (i.e. 0x800 = IP).
* @implements     Eth_FrameType_type
*/
typedef uint16 Eth_FrameType;

/**
* @brief         Type used to pass transmit or receive data to or from the driver.
* @details       This type was defined as 8 bit wide unsigned integer because
*                this definition is available on all CPU types.
* @implements     Eth_DataType_type
*/
typedef uint8 Eth_DataType;

/**
* @brief         Type used to identify the ethernet buffer. 
* @details       This type was defined for index of buffer used in transmitted and received data.
* @implements     Eth_BufIdxType_type
*/
typedef uint32 Eth_BufIdxType;

/**
* @brief         Type used to express the timestamp value.
* @details       Variables of this type are used for expressing time stamps including relative time
*                and absolute calendar time. The absolute time starts acc. to "[5], Annex C/C1"
*                specification at 1970-01-01.
*                0 to 281474976710655s
*                == 3257812230d
*                [0xFFFF FFFF FFFF]
*                0 to 999999999ns
*                [0x3B9A C9FF]
*                invalid value in nanoseconds: [0x3B9A CA00] to [0x3FFF FFFF]
*                Bit 30 and 31 reserved, default: 0
* @implements    Eth_TimeStampType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) nanoseconds;   /**< @brief Nanoseconds part of the time */
    VAR(uint32, ETH_VAR) seconds;       /**< @brief 32 bit LSB of the 48 bits Seconds part of the time */
    VAR(uint16, ETH_VAR) secondsHi;     /**< @brief 16 bit MSB of the 48 bits Seconds part of the time */
} Eth_TimeStampType;
/**
* @brief         Type used to express the diff between timestamp values.
* @details       Variables of this type are used to express time differences in a usual way. The
*                described "TimeInterval" type referenced in ", chapter 6.3.3.3" will not be used
*                and hereby slightly simplified.
* @implements    Eth_TimeIntDiffType_structure
*/
typedef struct
{
    VAR(Eth_TimeStampType, ETH_VAR) diff;   /**< @brief diff time difference */
    VAR(boolean, ETH_VAR) sign;       /**< @brief Positive (True) Or negative (False) time */
} Eth_TimeIntDiffType;
/**
* @brief         Type used to express frequency ratio.
* @details       Variables of this type are used to express frequency ratios.
* @implements    Eth_RateRatioType_structure
*/
typedef struct
{
    VAR(Eth_TimeIntDiffType, ETH_VAR) IngressTimeStampDelta;   /**< @brief   IngressTimeStampSync2 -IngressTimeStampSync1 */
    VAR(Eth_TimeIntDiffType, ETH_VAR) OriginTimeStampDelta;       /**< @brief OriginTimeStampSync2[FUP2]-OriginTimeStampSync1[FUP1] */
} Eth_RateRatioType;





 
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ETH_GENERALTYPES_H */
/** @} */
