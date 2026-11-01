/**
 * CCP5 Generated Driver File.
 * 
 * @file ccp5.c
 * 
 * @ingroup compare5
 * 
 * @brief This file contains the API implementation for the CCP5 driver.
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

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../ccp5.h"

/**
  Section: Compare Module APIs
*/

void CCP5_Initialize(void)
{
    // Set the CCP5 to the options selected in the User Interface

    // CCPM Autoconversion; DCB 0; 
    CCP5CON = 0xB;
   
    // CCPRH 0; 
    CCPR5H = 0x0;
  
    // CCPRL 0; 
    CCPR5L = 0x0;
   
    // Selecting Timer 3
    CCPTMRS1bits.C5TSEL = 0x1; 

}

void CCP5_SetCompareCount(uint16_t compareCount)
{
  CCPR5_PERIOD_REG_T module;
    
    // Write the 16-bit compare value
    module.ccpr5_16Bit = compareCount;
    
    CCPR5L = module.ccpr5l;
    CCPR5H = module.ccpr5h;
}

bool CCP5_IsCompareComplete(void)
{
    // Check if compare is complete by reading "CCPIF" flag.
    bool status = PIR4bits.CCP5IF;
    if(status)
        PIR4bits.CCP5IF = 0;
    return (status);
}

/**
 End of File
*/
