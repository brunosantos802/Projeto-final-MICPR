/**
 * ECCP2 Generated Driver File.
 * 
 * @file eccp2.c
 * 
 * @ingroup capture2
 * 
 * @brief This file contains the API implementation for the ECCP2 driver.
 *
 * @version ECCP2 Driver Version 1.0.0
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

#include <xc.h>
#include "../eccp2.h"

/**
 * @ingroup capture2
 * @brief Declares the function pointer for the callback API.
 */
static void (*ECCP2_CallBack)(uint16_t);

/**
 * @ingroup capture2
 * @brief Default callback function for the capture interrupt events.
 * @param capturedValue - 16-bit captured value
 * @return None.
 */
static void ECCP2_DefaultCallBack(uint16_t capturedValue) {
    // Add your code here
}

void ECCP2_Initialize(void)
{
    // Set the ECCP2 to the options selected in the User Interface
    
    // CCPM Every rising edge; DCB 0; PM single; 
    CCP2CON = 0x5;
    
    // CCPRH 0; 
    CCPR2H = 0x0;
    
    // CCPRL 0; 
    CCPR2L = 0x0;
    
    // Set the default call back function for ECCP2
    ECCP2_SetCallBack(ECCP2_DefaultCallBack);

    // Selecting Timer 5
    CCPTMRS0bits.C2TSEL = 0x2; 

    // Clear the ECCP2 interrupt flag    
    PIR2bits.CCP2IF = 0;
    
    // Enable the ECCP2 interrupt
    PIE2bits.CCP2IE = 1;
}

void ECCP2_CaptureISR(void)
{
    CCPR2_PERIOD_REG_T module;

    // Clear the ECCP2 interrupt flag
    PIR2bits.CCP2IF = 0;
    
    // Copy captured value.
    module.ccpr2l = CCPR2L;
    module.ccpr2h = CCPR2H;
    
    // Return 16-bit captured value
    ECCP2_CallBack(module.ccpr2_16Bit);
}

void ECCP2_SetCallBack(void (*customCallBack)(uint16_t)){
    ECCP2_CallBack = customCallBack;
}
/**
 End of File
*/
