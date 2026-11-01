/**
 * TMR3 Generated Driver API Header File
 *
 * @file tmr3.h
 *
 * @defgroup tmr3 TMR3
 *
 * @brief This file contains the deprecated macros or APIs for the TMR3 driver.
 *
 * @version TMR3 Driver Version 2.1.0
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

#ifndef TMR3_DEPRECATED_H
#define TMR3_DEPRECATED_H

#warning "The tmr3_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MPLAB® Code Configurator (MCC) Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterGet API.
 *        The TMR3_Read will be deprecated in the future release. Use TMR3_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_Read TMR3_CounterGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterGet API.
 *        The Timer3_Read will be deprecated in the future release. Use Timer3_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Read TMR3_CounterGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterSet API.
 *        The TMR3_Write will be deprecated in the future release. Use TMR3_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_Write TMR3_CounterSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterSet API.
 *        The Timer3_Write will be deprecated in the future release. Use Timer3_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Write TMR3_CounterSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_PeriodSet API.
 *        The TMR3_PeriodCountSet will be deprecated in the future release. Use TMR3_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_PeriodCountSet TMR3_PeriodSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_PeriodSet API.
 *        The Timer3_PeriodCountSet will be deprecated in the future release. Use Timer3_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_PeriodCountSet TMR3_PeriodSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateStateGet API.
 *        The TMR3_CheckGateValueStatus will be deprecated in the future release. Use TMR3_GateStateGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_CheckGateValueStatus TMR3_GateStateGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateStateGet API.
 *        The Timer3_CheckGateValueStatus will be deprecated in the future release. Use Timer3_GateStateGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_CheckGateValueStatus TMR3_GateStateGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_SinglePulseAcquisitionStart API.
 *        The TMR3_StartSinglePulseAcquisition will be deprecated in the future release. Use TMR3_SinglePulseAcquisitionStart instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_StartSinglePulseAcquisition TMR3_SinglePulseAcquisitionStart
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_SinglePulseAcquisitionStart API.
 *        The Timer3_StartSinglePulseAcquisition will be deprecated in the future release. Use Timer3_SinglePulseAcquisitionStart instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_StartSinglePulseAcquisition TMR3_SinglePulseAcquisitionStart
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_OverflowStatusGet API.
 *        The TMR3_HasOverflowOccured will be deprecated in the future release. Use TMR3_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_HasOverflowOccured TMR3_OverflowStatusGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_OverflowStatusGet API.
 *        The Timer3_HasOverflowOccured will be deprecated in the future release. Use Timer3_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_HasOverflowOccured TMR3_OverflowStatusGet

#endif // TMR3_DEPRECATED_H