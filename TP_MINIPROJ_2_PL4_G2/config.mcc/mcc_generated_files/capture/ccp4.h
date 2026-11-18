/**
 * CCP4 Generated Driver API Header File.
 * 
 * @file ccp4.h
 * 
 * @defgroup capture4 CAPTURE4
 * 
 * @brief This file contains the API prototypes and other data types for the CCP4 module.
 *
 * @version CCP4 Driver Version 1.1.0
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

#ifndef CCP4_H
#define CCP4_H

 /**
   Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


/** 
   Section: Data Type Definition
*/

/**
 * @ingroup capture4
 * @union CCPR4_PERIOD_REG_T
 * @brief Custom data type to hold the low byte, high byte, and 16-bit values of the period register.
 */
typedef union CCPR4Reg_tag
{
   struct
   {
      uint8_t ccpr4l; /**< CCPR4L low byte.*/
      uint8_t ccpr4h; /**< CCPR4H high byte.*/
   };
   struct
   {
      uint16_t ccpr4_16Bit; /**< CCPR4 16-bit.*/
   };
} CCPR4_PERIOD_REG_T ;

/**
  Section: CCP4 Capture Module APIs
*/

/**
 * @ingroup capture4
 * @brief Initializes the CCP4 module. This is called only once before calling other CCP4 APIs.
 * @param None.
 * @return None.
 */
void CCP4_Initialize(void);

/**
 * @ingroup capture4
 * @brief Implements the Interrupt Service Routine (ISR) for the capture interrupt.
 * @param None.
 * @return None.
 */
void CCP4_CaptureISR(void);

/**
 * @ingroup capture4
 * @brief Assigns a callback function that will be called from the Capture ISR when a capture interrupt event occurs.
 * @param (*customCallBack)(uint16_t) - Function pointer to the new callback.
 * @return None.
 */
void CCP4_SetCallBack(void (*customCallBack)(uint16_t));


#endif // CCP4_H
/**
 End of File
*/