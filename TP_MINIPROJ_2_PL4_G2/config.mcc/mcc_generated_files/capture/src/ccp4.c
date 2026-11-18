/**
 * CCP4 Generated Driver File.
 * 
 * @file ccp4.c
 * 
 * @ingroup capture4
 * 
 * @brief This file contains the API implementation for the CCP4 driver.
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

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../ccp4.h"

static void (*CCP4_CallBack)(uint16_t);

/**
  Section: Capture Module APIs
*/

/**
 * @ingroup capture4
 * @brief Default callback function for the capture interrupt events.
 * @param capturedValue - 16-bit captured value.
 * @return None.
 */
static void CCP4_DefaultCallBack(uint16_t capturedValue) {
    // Add your code here
}

void CCP4_Initialize(void)
{
    // Set the CCP4 to the options selected in the User Interface
    
    // CCPM Rising edge; DCB 0; 
    CCP4CON = 0x5;
    
    // CCPRH 0; 
    CCPR4H = 0x0;
    
    // CCPRL 0; 
    CCPR4L = 0x0;
    
    // Set the default call back function for CCP4
    CCP4_SetCallBack(CCP4_DefaultCallBack);
     
    // Selecting Timer 5
    CCPTMRS1bits.C4TSEL = 0x2; 

    // Clear the CCP4 interrupt flag    
    PIR4bits.CCP4IF = 0;    
    
    // Enable the CCP4 interrupt
    PIE4bits.CCP4IE = 1;
}


/**
 * @ingroup capture4
 * @brief Implements the ISR for capture interrupt when vectored interrupt is enabled.
 * @param None.
 * @return None.
 */
void CCP4_CaptureISR(void)
{
    CCPR4_PERIOD_REG_T module;

    // Clear the CCP4 interrupt flag
    PIR4bits.CCP4IF = 0;
    
    // Copy captured value.
    module.ccpr4l = CCPR4L;
    module.ccpr4h = CCPR4H;
    
    // Return 16-bit captured value
    CCP4_CallBack(module.ccpr4_16Bit);
}

void CCP4_SetCallBack(void (*customCallBack)(uint16_t)){
    CCP4_CallBack = customCallBack;
}
/**
 End of File
*/
