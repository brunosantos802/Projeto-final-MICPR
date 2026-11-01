/**
  * TMR3 Generated Driver File
  *
  * @file tmr3.c
  *
  * @ingroup tmr3
  *
  * @brief This file contains the API implementation for the TMR3 driver.
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

/**
   Section: Included Files
*/

#include <xc.h>
#include "../tmr3.h"

/**
 * @misradeviation{@advisory,8.7}
 * The TMRx_CounterSet function is declared in a header file that can be included in any translation unit that must use it. 
 */

static volatile uint16_t timer3ReloadVal;
static void (*TMR3_OverflowCallback)(void);
static void TMR3_DefaultOverflowCallback(void);
static void (*TMR3_GateCallback)(void);
static void TMR3_DefaultGateCallback(void);

void TMR3_Initialize(void)
{
    T3CONbits.TMR3ON = 0U;
	
    TMR3H = 0x6D;                       // Period 50 ms; Count 28,036
    TMR3L = 0x84;

    timer3ReloadVal=((uint16_t)TMR3H << 8U) | TMR3L;
	
    T3GCON = (0 << _T3GCON_T3GSS_POSN)   // T3GSS T3G_pin
        | (0 << _T3GCON_T3GGO_POSN)   // T3GGO done
        | (0 << _T3GCON_T3GSPM_POSN)   // T3GSPM disabled
        | (0 << _T3GCON_T3GTM_POSN)   // T3GTM disabled
        | (0 << _T3GCON_T3GPOL_POSN)   // T3GPOL low
        | (0 << _T3GCON_TMR3GE_POSN);  // TMR3GE disabled
    TMR3_OverflowCallback =TMR3_DefaultOverflowCallback;
    TMR3_GateCallback = TMR3_DefaultGateCallback;

    // Clear interrupt flags
	PIR2bits.TMR3IF = 0U;
	PIR3bits.TMR3GIF = 0U;
    
    T3CON = (1 << _T3CON_TMR3ON_POSN)   // TMR3ON enabled
        | (1 << _T3CON_nT3SYNC_POSN)   // nT3SYNC do_not_synchronize
        | (2 << _T3CON_T3CKPS_POSN)   // T3CKPS 1:4
        | (0 << _T3CON_TMR3CS_POSN)   // TMR3CS FOSC/4
        | (0 << _T3CON_T3OSCEN_POSN)   // T3OSCEN disabled
        | (0 << _T3CON_T3RD16_POSN);  // T3RD16 disabled
}

void TMR3_Deinitialize(void)
{
    T3CONbits.TMR3ON = 0U;
    	   
    PIE2bits.TMR3IE = 0U;
    PIR2bits.TMR3IF = 0U;
    PIE3bits.TMR3GIE = 0U;
    PIR3bits.TMR3GIF = 0U;	
    
    T3CON = 0x0U;
    T3GCON = 0x0U;
    TMR3H = 0x0U;
    TMR3L = 0x0U;
}

void TMR3_Start(void)
{
    T3CONbits.TMR3ON = 1U;
}

void TMR3_Stop(void)
{
    T3CONbits.TMR3ON = 0U;
}

uint16_t TMR3_CounterGet(void)
{
    uint16_t counterValue;
    uint8_t counterHighByte;
    uint8_t counterLowByte;
    
    counterLowByte = TMR3L;
    counterHighByte = TMR3H;    
    counterValue = ((uint16_t)counterHighByte << 8U) | counterLowByte;

    return counterValue;
}

/* cppcheck-suppress misra-c2012-8.7 */
void TMR3_CounterSet(uint16_t timerVal)
{
    if (1U == T3CONbits.nT3SYNC)
    {
	    bool onState = T3CONbits.TMR3ON;	
		
        T3CONbits.TMR3ON = 0U;
        
        TMR3H = (uint8_t)(timerVal >> 8U);
        TMR3L = (uint8_t)timerVal;

        T3CONbits.TMR3ON = onState;
    }
    else
    {
        TMR3H = (uint8_t)(timerVal >> 8U);
        TMR3L = (uint8_t)timerVal;
    }
}

void TMR3_Reload(void)
{
    /* cppcheck-suppress misra-c2012-8.7 */
    TMR3_CounterSet(timer3ReloadVal);
}

uint16_t TMR3_MaxCountGet(void)
{
    return TMR3_MAX_COUNT;
}

void TMR3_PeriodSet(uint16_t periodVal)
{
    timer3ReloadVal = periodVal;
}

uint16_t TMR3_PeriodGet(void)
{
    return timer3ReloadVal;
}

void TMR3_SinglePulseAcquisitionStart(void)
{
    T3GCONbits.T3GGO = 1U;
}

uint8_t TMR3_GateStateGet(void)
{
    return (T3GCONbits.T3GVAL);
}

bool TMR3_OverflowStatusGet(void)
{
    return(PIR2bits.TMR3IF);
}

void TMR3_OverflowStatusClear(void)
{
    PIR2bits.TMR3IF = 0U;
}

bool TMR3_GateEventStatusGet(void)
{
    return(PIR3bits.TMR3GIF);
}

void TMR3_GateEventStatusClear(void)
{
    PIR3bits.TMR3GIF = 0U;
}

void TMR3_Tasks(void)
{
    if(1U == PIR2bits.TMR3IF)
    {
        /* cppcheck-suppress misra-c2012-8.7 */
        TMR3_CounterSet(timer3ReloadVal);
        if(NULL != TMR3_OverflowCallback)
        { 
            TMR3_OverflowCallback();
        }
        PIR2bits.TMR3IF = 0;
    }
    if(1U == PIR3bits.TMR3GIF)
    {
         if(NULL != TMR3_GateCallback)
        {
            TMR3_GateCallback();
        }
        PIR3bits.TMR3GIF = 0;
    }
}


void TMR3_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    TMR3_OverflowCallback = CallbackHandler;
}

static void TMR3_DefaultOverflowCallback(void)
{
    // Use TMR3_OverflowCallbackRegister function to register custom callback
}

void TMR3_GateCallbackRegister(void (* CallbackHandler)(void))
{
    TMR3_GateCallback = CallbackHandler;
}

static void TMR3_DefaultGateCallback(void)
{
    // Use TMR3_GateCallbackRegister function to register custom callback
}

/**
  End of File
*/
