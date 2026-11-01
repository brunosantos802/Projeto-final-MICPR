
/**
 * TMR3 Generated Peripheral Driver API Header File
 *
 * @file tmr3.h
 *
 * @defgroup tmr3 TMR3
 *
 * @brief This file contains the API prototypes and other data types for the TMR3 driver.
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

#ifndef TMR3_H
#define TMR3_H

#include <stdbool.h>
#include <stdint.h>
#include "tmr3_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MPLAB® Code Configurator (MCC) Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr3
 * @brief Defines the TMR3 maximum count value
 */
#define TMR3_MAX_COUNT (65535U)
/**
 * @ingroup tmr3
 * @brief Defines the TMR3 prescaled frequency in hertz.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TMR3_CLOCK_FREQ (750000UL)
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Initialize API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Initialize TMR3_Initialize
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Deinitialize API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Deinitialize TMR3_Deinitialize
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Start API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Start TMR3_Start
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Stop API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Stop TMR3_Stop
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_CounterGet TMR3_CounterGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_CounterSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_CounterSet TMR3_CounterSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_PeriodSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_PeriodSet TMR3_PeriodSet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_PeriodGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_PeriodGet TMR3_PeriodGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Reload API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Reload TMR3_Reload
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_MaxCountGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_MaxCountGet TMR3_MaxCountGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_OverflowCallbackRegister API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_OverflowCallbackRegister TMR3_OverflowCallbackRegister
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_Tasks API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_Tasks TMR3_Tasks
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_OverflowStatusGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
 #define Timer3_OverflowStatusGet TMR3_OverflowStatusGet
 /**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_OverflowStatusClear API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_OverflowStatusClear TMR3_OverflowStatusClear
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateStateGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_GateStateGet TMR3_GateStateGet
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_SinglePulseAcquisitionStart API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_SinglePulseAcquisitionStart TMR3_SinglePulseAcquisitionStart
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateCallbackRegister API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_GateCallbackRegister TMR3_GateCallbackRegister
/**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateEventStatusGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
 #define Timer3_GateEventStatusGet TMR3_GateEventStatusGet
 /**
 * @ingroup tmr3
 * @brief Defines the Custom Name for the \ref TMR3_GateEventStatusClear API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer3_GateEventStatusClear TMR3_GateEventStatusClear

/**
  Section: TMR3 APIs
*/

/**
 * @ingroup tmr3
 * @brief Initializes the TMR3 module. This routine must be called before any other timer routines.
 * @param None.
 * @return None.
 */
void TMR3_Initialize(void);

/**
 * @ingroup tmr3
 * @brief Deinitializes the TMR3 module.
 * @param None.
 * @return None.
 */
void TMR3_Deinitialize(void);

/**
 * @ingroup tmr3
 * @brief Starts TMR3.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR3_Start(void);

/**
 * @ingroup tmr3
 * @brief Stops TMR3.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR3_Stop(void);

/**
 * @ingroup tmr3
 * @brief Reads the 16-bit value from the TMR3 register.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param None.
 * @return 16-bit data from the TMR3 register
 */
uint16_t TMR3_CounterGet(void);

/**
 * @ingroup tmr3
 * @brief Writes the 16-bit value to the TMR3 register.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param timerVal - 16-bit value to be written to the TMR3 register
 * @return None.
 */
void TMR3_CounterSet(uint16_t timerVal);

/**
 * @ingroup tmr3
 * @brief Loads the 16-bit value to the PR3 register.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param periodVal - 16-bit value written to the PR3 register
 * @return None.
 */
void TMR3_PeriodSet(uint16_t periodVal);

/**
 * @ingroup tmr3
 * @brief Returns the TMR3 period count value.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param None.
 * @return TMR3 period count value
 */
uint16_t TMR3_PeriodGet(void);

/**
 * @ingroup tmr3
 * @brief Loads the 16-bit value to the TMR3 register.
 * @pre Initialize TMR3 with TMR3_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR3_Reload(void);

/**
 * @ingroup tmr3
 * @brief Returns the TMR3 maximum count value.
 * @param None.
 * @return TMR3 maximum count value
 */
uint16_t TMR3_MaxCountGet(void);

/**
 * @ingroup tmr3
 * @brief Starts the single-pulse acquisition in TMR3 gate operation.
 * @pre This function must be used when the TMR3 Gate is enabled.
 * @param None.
 * @return None.
 */
void TMR3_SinglePulseAcquisitionStart(void);

/**
 * @ingroup tmr3
 * @brief Reads the TMR3 gate value and returns it.
 * @pre This function must be used once the TMR3 Gate is enabled.
 * @param None.
 * @return Gate value status
 */
uint8_t TMR3_GateStateGet(void);

/**
 * @ingroup tmr3
 * @brief Checks for the Timer Overflow flag when in Non-Interrupt mode.
 * @param None.
 * @retval True  - Timer overflow has occurred.
 * @retval False - Timer overflow has not occurred.
 */
bool TMR3_OverflowStatusGet(void);

/**
 * @ingroup tmr3
 * @brief Clears the Timer Overflow flag in Non-Interrupt mode.
 * @param None.
 * @retval None.
 */
void TMR3_OverflowStatusClear(void);

/**
 * @ingroup tmr3
 * @brief Returns the TMR3 Gate flag status in Non-Interrupt mode.
 * @param None.
 * @retval True  - Timer gate event has occurred.
 * @retval False - Timer gate event has not occurred.
 */
bool TMR3_GateEventStatusGet(void);

/**
 * @ingroup tmr3
 * @brief Clears the TMR3 Gate flag in Non-Interrupt mode.
 * @param None.
 * @retval None.
 */
void TMR3_GateEventStatusClear(void);

/**
 * @ingroup tmr3
 * @brief Registers a callback function for the TMR3 gate event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR3_GateCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tmr3
 * @brief Registers a callback function for the TMR3 overflow event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR3_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tmr3
 * @brief Performs the tasks to be executed during the timer overflow event or gate event.
 * @param None.
 * @return None.
 */
void TMR3_Tasks(void);

#endif // TMR3_H

/**
 End of File
*/
