/**
  * TMR5 Generated Driver File
  *
  * @file tmr5.c
  *
  * @ingroup tmr5
  *
  * @brief This file contains the API implementation for the TMR5 driver.
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

/**
   Section: Included Files
*/

#include <xc.h>
#include "../tmr5.h"

/**
 * @misradeviation{@advisory,8.7}
 * The TMRx_CounterSet function is declared in a header file that can be included in any translation unit that must use it. 
 */

static volatile uint16_t timer5ReloadVal;
static void (*TMR5_OverflowCallback)(void);
static void TMR5_DefaultOverflowCallback(void);
static void (*TMR5_GateCallback)(void);
static void TMR5_DefaultGateCallback(void);

void TMR5_Initialize(void)
{
    T5CONbits.TMR5ON = 0U;
	
    TMR5H = 0x0;                       // Period 174.76267 ms; Count 0
    TMR5L = 0x0;

    timer5ReloadVal=((uint16_t)TMR5H << 8U) | TMR5L;
	
    T5GCON = (0 << _T5GCON_T5GSS_POSN)   // T5GSS T5G_pin
        | (0 << _T5GCON_T5GGO_POSN)   // T5GGO done
        | (0 << _T5GCON_T5GSPM_POSN)   // T5GSPM disabled
        | (0 << _T5GCON_T5GTM_POSN)   // T5GTM disabled
        | (0 << _T5GCON_T5GPOL_POSN)   // T5GPOL low
        | (0 << _T5GCON_TMR5GE_POSN);  // TMR5GE disabled
    TMR5_OverflowCallback =TMR5_DefaultOverflowCallback;
    TMR5_GateCallback = TMR5_DefaultGateCallback;

    // Clear interrupt flags
	PIR5bits.TMR5IF = 0U;
	PIR3bits.TMR5GIF = 0U;
    
    T5CON = (1 << _T5CON_TMR5ON_POSN)   // TMR5ON enabled
        | (1 << _T5CON_T5SYNC_POSN)   // T5SYNC do_not_synchronize
        | (3 << _T5CON_T5CKPS_POSN)   // T5CKPS 1:8
        | (0 << _T5CON_TMR5CS_POSN)   // TMR5CS FOSC/4
        | (0 << _T5CON_T5SOSCEN_POSN)   // T5SOSCEN disabled
        | (1 << _T5CON_T5RD16_POSN);  // T5RD16 enabled
}

void TMR5_Deinitialize(void)
{
    T5CONbits.TMR5ON = 0U;
    	   
    PIE5bits.TMR5IE = 0U;
    PIR5bits.TMR5IF = 0U;
    PIE3bits.TMR5GIE = 0U;
    PIR3bits.TMR5GIF = 0U;	
    
    T5CON = 0x0U;
    T5GCON = 0x0U;
    TMR5H = 0x0U;
    TMR5L = 0x0U;
}

void TMR5_Start(void)
{
    T5CONbits.TMR5ON = 1U;
}

void TMR5_Stop(void)
{
    T5CONbits.TMR5ON = 0U;
}

uint16_t TMR5_CounterGet(void)
{
    uint16_t counterValue;
    uint8_t counterHighByte;
    uint8_t counterLowByte;
    
    T5CONbits.T5RD16 = 1U;
	
    counterLowByte = TMR5L;
    counterHighByte = TMR5H;    
    counterValue = ((uint16_t)counterHighByte << 8U) | counterLowByte;

    return counterValue;
}

/* cppcheck-suppress misra-c2012-8.7 */
void TMR5_CounterSet(uint16_t timerVal)
{
    if (1U == T5CONbits.T5SYNC)
    {
	    bool onState = T5CONbits.TMR5ON;	
		
        T5CONbits.TMR5ON = 0U;
        
        TMR5H = (uint8_t)(timerVal >> 8U);
        TMR5L = (uint8_t)timerVal;

        T5CONbits.TMR5ON = onState;
    }
    else
    {
        TMR5H = (uint8_t)(timerVal >> 8U);
        TMR5L = (uint8_t)timerVal;
    }
}

void TMR5_Reload(void)
{
    /* cppcheck-suppress misra-c2012-8.7 */
    TMR5_CounterSet(timer5ReloadVal);
}

uint16_t TMR5_MaxCountGet(void)
{
    return TMR5_MAX_COUNT;
}

void TMR5_PeriodSet(uint16_t periodVal)
{
    timer5ReloadVal = periodVal;
}

uint16_t TMR5_PeriodGet(void)
{
    return timer5ReloadVal;
}

void TMR5_SinglePulseAcquisitionStart(void)
{
    T5GCONbits.T5GGO = 1U;
}

uint8_t TMR5_GateStateGet(void)
{
    return (T5GCONbits.T5GVAL);
}

bool TMR5_OverflowStatusGet(void)
{
    return(PIR5bits.TMR5IF);
}

void TMR5_OverflowStatusClear(void)
{
    PIR5bits.TMR5IF = 0U;
}

bool TMR5_GateEventStatusGet(void)
{
    return(PIR3bits.TMR5GIF);
}

void TMR5_GateEventStatusClear(void)
{
    PIR3bits.TMR5GIF = 0U;
}

void TMR5_Tasks(void)
{
    if(1U == PIR5bits.TMR5IF)
    {
        /* cppcheck-suppress misra-c2012-8.7 */
        TMR5_CounterSet(timer5ReloadVal);
        if(NULL != TMR5_OverflowCallback)
        { 
            TMR5_OverflowCallback();
        }
        PIR5bits.TMR5IF = 0;
    }
    if(1U == PIR3bits.TMR5GIF)
    {
         if(NULL != TMR5_GateCallback)
        {
            TMR5_GateCallback();
        }
        PIR3bits.TMR5GIF = 0;
    }
}


void TMR5_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    TMR5_OverflowCallback = CallbackHandler;
}

static void TMR5_DefaultOverflowCallback(void)
{
    // Use TMR5_OverflowCallbackRegister function to register custom callback
}

void TMR5_GateCallbackRegister(void (* CallbackHandler)(void))
{
    TMR5_GateCallback = CallbackHandler;
}

static void TMR5_DefaultGateCallback(void)
{
    // Use TMR5_GateCallbackRegister function to register custom callback
}

/**
  End of File
*/
