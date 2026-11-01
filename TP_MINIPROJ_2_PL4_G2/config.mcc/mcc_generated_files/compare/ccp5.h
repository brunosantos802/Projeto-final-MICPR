/**
 * CCP5 Generated Driver API Header File.
 * 
 * @file ccp5.h
 * 
 * @defgroup compare5 COMPARE5
 * 
 * @brief This file contains the API prototypes and other data types for the CCP5 module.
 *
 * @version CCP5 Driver Version 1.1.0
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

#ifndef CCP5_H
#define CCP5_H

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
 * @ingroup compare5
 * @union CCPR5_PERIOD_REG_T
 * @brief Custom data type to hold the low byte, high byte, and 16-bit values of the period register.
 */
typedef union CCPR5Reg_tag
{
   struct
   {
      uint8_t ccpr5l;
      uint8_t ccpr5h;
   };
   struct
   {
      uint16_t ccpr5_16Bit;
   };
} CCPR5_PERIOD_REG_T ;

/**
  Section: Compare Module APIs
*/

/**
 * @ingroup compare5
 * @brief Initializes the CCP5 module. This is called only once before calling other CCP5 APIs.
 * @param None.
 * @return None.
 */
void CCP5_Initialize(void);

/**
 * @ingroup compare5
 * @brief Sets the 16-bit Compare value.
 * @pre CCP5_Initialize() is already called.
 * @param compareCount - 16-bit unsigned value.
 * @return None.
 */
void CCP5_SetCompareCount(uint16_t compareCount);


/**
 * @ingroup compare5
 * @brief Determines if the data comparison is complete or not.
 * @pre CCP5_Initialize() is already called.
 * @param None.
 * @retval True - CCP5 if data comparison is complete.
 * @retval False - CCP5 if data comparison is not yet complete.
 */
bool CCP5_IsCompareComplete(void);

#endif //CCP5_H
/**
 End of File
*/