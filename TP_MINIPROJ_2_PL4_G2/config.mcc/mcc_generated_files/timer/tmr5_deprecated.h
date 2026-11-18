/**
 * TMR5 Generated Driver API Header File
 *
 * @file tmr5.h
 *
 * @defgroup tmr5 TMR5
 *
 * @brief This file contains the deprecated macros or APIs for the TMR5 driver.
 *
 * @version TMR5 Driver Version 2.1.0
 * 
 * @version Package Version 2.1.0
 */
/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef TMR5_DEPRECATED_H
#define TMR5_DEPRECATED_H

#warning "The tmr5_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MPLAB® Code Configurator (MCC) Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterGet API.
 *        The TMR5_Read will be deprecated in the future release. Use TMR5_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_Read TMR5_CounterGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterGet API.
 *        The Timer5_Read will be deprecated in the future release. Use Timer5_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Read TMR5_CounterGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterSet API.
 *        The TMR5_Write will be deprecated in the future release. Use TMR5_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_Write TMR5_CounterSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterSet API.
 *        The Timer5_Write will be deprecated in the future release. Use Timer5_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Write TMR5_CounterSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_PeriodSet API.
 *        The TMR5_PeriodCountSet will be deprecated in the future release. Use TMR5_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_PeriodCountSet TMR5_PeriodSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_PeriodSet API.
 *        The Timer5_PeriodCountSet will be deprecated in the future release. Use Timer5_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_PeriodCountSet TMR5_PeriodSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateStateGet API.
 *        The TMR5_CheckGateValueStatus will be deprecated in the future release. Use TMR5_GateStateGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_CheckGateValueStatus TMR5_GateStateGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateStateGet API.
 *        The Timer5_CheckGateValueStatus will be deprecated in the future release. Use Timer5_GateStateGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_CheckGateValueStatus TMR5_GateStateGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_SinglePulseAcquisitionStart API.
 *        The TMR5_StartSinglePulseAcquisition will be deprecated in the future release. Use TMR5_SinglePulseAcquisitionStart instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_StartSinglePulseAcquisition TMR5_SinglePulseAcquisitionStart
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_SinglePulseAcquisitionStart API.
 *        The Timer5_StartSinglePulseAcquisition will be deprecated in the future release. Use Timer5_SinglePulseAcquisitionStart instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_StartSinglePulseAcquisition TMR5_SinglePulseAcquisitionStart
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowStatusGet API.
 *        The TMR5_HasOverflowOccured will be deprecated in the future release. Use TMR5_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_HasOverflowOccured TMR5_OverflowStatusGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowStatusGet API.
 *        The Timer5_HasOverflowOccured will be deprecated in the future release. Use Timer5_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_HasOverflowOccured TMR5_OverflowStatusGet

#endif // TMR5_DEPRECATED_H