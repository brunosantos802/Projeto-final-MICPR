
/**
 * TMR5 Generated Peripheral Driver API Header File
 *
 * @file tmr5.h
 *
 * @defgroup tmr5 TMR5
 *
 * @brief This file contains the API prototypes and other data types for the TMR5 driver.
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

#ifndef TMR5_H
#define TMR5_H

#include <stdbool.h>
#include <stdint.h>
#include "tmr5_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MPLAB® Code Configurator (MCC) Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr5
 * @brief Defines the TMR5 maximum count value
 */
#define TMR5_MAX_COUNT (65535U)
/**
 * @ingroup tmr5
 * @brief Defines the TMR5 prescaled frequency in hertz.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TMR5_CLOCK_FREQ (375000UL)
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Initialize API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Initialize TMR5_Initialize
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Deinitialize API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Deinitialize TMR5_Deinitialize
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Start API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Start TMR5_Start
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Stop API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Stop TMR5_Stop
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_CounterGet TMR5_CounterGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_CounterSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_CounterSet TMR5_CounterSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_PeriodSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_PeriodSet TMR5_PeriodSet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_PeriodGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_PeriodGet TMR5_PeriodGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Reload API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Reload TMR5_Reload
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_MaxCountGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_MaxCountGet TMR5_MaxCountGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowCallbackRegister API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_OverflowCallbackRegister TMR5_OverflowCallbackRegister
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowISR API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_OverflowISR TMR5_OverflowISR
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_Tasks API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_Tasks TMR5_Tasks
 /**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowInterruptEnable API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_OverflowInterruptEnable TMR5_OverflowInterruptEnable
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_OverflowInterruptDisable API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_OverflowInterruptDisable TMR5_OverflowInterruptDisable
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateStateGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_GateStateGet TMR5_GateStateGet
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_SinglePulseAcquisitionStart API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_SinglePulseAcquisitionStart TMR5_SinglePulseAcquisitionStart
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateCallbackRegister API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_GateCallbackRegister TMR5_GateCallbackRegister
/**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateEventStatusGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
 #define Timer5_GateEventStatusGet TMR5_GateEventStatusGet
 /**
 * @ingroup tmr5
 * @brief Defines the Custom Name for the \ref TMR5_GateEventStatusClear API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer5_GateEventStatusClear TMR5_GateEventStatusClear

/**
  Section: TMR5 APIs
*/

/**
 * @ingroup tmr5
 * @brief Initializes the TMR5 module. This routine must be called before any other timer routines.
 * @param None.
 * @return None.
 */
void TMR5_Initialize(void);

/**
 * @ingroup tmr5
 * @brief Deinitializes the TMR5 module.
 * @param None.
 * @return None.
 */
void TMR5_Deinitialize(void);

/**
 * @ingroup tmr5
 * @brief Starts TMR5.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR5_Start(void);

/**
 * @ingroup tmr5
 * @brief Stops TMR5.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR5_Stop(void);

/**
 * @ingroup tmr5
 * @brief Reads the 16-bit value from the TMR5 register.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param None.
 * @return 16-bit data from the TMR5 register
 */
uint16_t TMR5_CounterGet(void);

/**
 * @ingroup tmr5
 * @brief Writes the 16-bit value to the TMR5 register.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param timerVal - 16-bit value to be written to the TMR5 register
 * @return None.
 */
void TMR5_CounterSet(uint16_t timerVal);

/**
 * @ingroup tmr5
 * @brief Loads the 16-bit value to the PR5 register.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param periodVal - 16-bit value written to the PR5 register
 * @return None.
 */
void TMR5_PeriodSet(uint16_t periodVal);

/**
 * @ingroup tmr5
 * @brief Returns the TMR5 period count value.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param None.
 * @return TMR5 period count value
 */
uint16_t TMR5_PeriodGet(void);

/**
 * @ingroup tmr5
 * @brief Loads the 16-bit value to the TMR5 register.
 * @pre Initialize TMR5 with TMR5_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR5_Reload(void);

/**
 * @ingroup tmr5
 * @brief Returns the TMR5 maximum count value.
 * @param None.
 * @return TMR5 maximum count value
 */
uint16_t TMR5_MaxCountGet(void);

/**
 * @ingroup tmr5
 * @brief Starts the single-pulse acquisition in TMR5 gate operation.
 * @pre This function must be used when the TMR5 Gate is enabled.
 * @param None.
 * @return None.
 */
void TMR5_SinglePulseAcquisitionStart(void);

/**
 * @ingroup tmr5
 * @brief Reads the TMR5 gate value and returns it.
 * @pre This function must be used once the TMR5 Gate is enabled.
 * @param None.
 * @return Gate value status
 */
uint8_t TMR5_GateStateGet(void);

/**
 * @ingroup tmr5
 * @brief Enables TMR5 interrupt.
 * @param None.
 * @return None.
 */
void TMR5_OverflowInterruptEnable(void);

/**
 * @ingroup tmr5
 * @brief Disables  TMR5 interrupt.
 * @param None.
 * @return None.
 */
void TMR5_OverflowInterruptDisable(void);

/**
 * @ingroup tmr5
 * @brief Interrupt Service Routine (ISR) for TMR5 overflow interrupt.
 * @param None.
 * @return None.
 */
void TMR5_OverflowISR(void);

/**
 * @ingroup tmr5
 * @brief Returns the TMR5 Gate flag status in Non-Interrupt mode.
 * @param None.
 * @retval True  - Timer gate event has occurred.
 * @retval False - Timer gate event has not occurred.
 */
bool TMR5_GateEventStatusGet(void);

/**
 * @ingroup tmr5
 * @brief Clears the TMR5 Gate flag in Non-Interrupt mode.
 * @param None.
 * @retval None.
 */
void TMR5_GateEventStatusClear(void);

/**
 * @ingroup tmr5
 * @brief Registers a callback function for the TMR5 gate event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR5_GateCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tmr5
 * @brief Registers a callback function for the TMR5 overflow event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR5_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tmr5
 * @brief Performs the tasks to be executed during the timer overflow event or gate event.
 * @param None.
 * @return None.
 */
void TMR5_Tasks(void);

#endif // TMR5_H

/**
 End of File
*/
