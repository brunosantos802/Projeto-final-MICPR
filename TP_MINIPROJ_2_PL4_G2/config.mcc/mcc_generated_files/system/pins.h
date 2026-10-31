/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define POT_TRIS                 TRISAbits.TRISA0
#define POT_LAT                  LATAbits.LATA0
#define POT_PORT                 PORTAbits.RA0
#define POT_WPU                  WPUAbits.
#define POT_OD                   ODCONAbits.
#define POT_ANS                  ANSELAbits.ANSA0
#define POT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT_GetValue()           PORTAbits.RA0
#define POT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits. = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 aliases
#define LED1_TRIS                 TRISAbits.TRISA1
#define LED1_LAT                  LATAbits.LATA1
#define LED1_PORT                 PORTAbits.RA1
#define LED1_WPU                  WPUAbits.
#define LED1_OD                   ODCONAbits.
#define LED1_ANS                  ANSELAbits.ANSA1
#define LED1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED1_GetValue()           PORTAbits.RA1
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUAbits. = 1; } while(0)
#define LED1_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 aliases
#define LED2_TRIS                 TRISAbits.TRISA2
#define LED2_LAT                  LATAbits.LATA2
#define LED2_PORT                 PORTAbits.RA2
#define LED2_WPU                  WPUAbits.
#define LED2_OD                   ODCONAbits.
#define LED2_ANS                  ANSELAbits.ANSA2
#define LED2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED2_GetValue()           PORTAbits.RA2
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits. = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 aliases
#define LED3_TRIS                 TRISAbits.TRISA3
#define LED3_LAT                  LATAbits.LATA3
#define LED3_PORT                 PORTAbits.RA3
#define LED3_WPU                  WPUAbits.
#define LED3_OD                   ODCONAbits.
#define LED3_ANS                  ANSELAbits.ANSA3
#define LED3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED3_GetValue()           PORTAbits.RA3
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits. = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RA4 aliases
#define TMR_ENC_TRIS                 TRISAbits.TRISA4
#define TMR_ENC_LAT                  LATAbits.LATA4
#define TMR_ENC_PORT                 PORTAbits.RA4
#define TMR_ENC_WPU                  WPUAbits.
#define TMR_ENC_OD                   ODCONAbits.
#define TMR_ENC_ANS                  ANSELAbits.
#define TMR_ENC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define TMR_ENC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define TMR_ENC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define TMR_ENC_GetValue()           PORTAbits.RA4
#define TMR_ENC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define TMR_ENC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define TMR_ENC_SetPullup()          do { WPUAbits. = 1; } while(0)
#define TMR_ENC_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define TMR_ENC_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define TMR_ENC_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define TMR_ENC_SetAnalogMode()      do { ANSELAbits. = 1; } while(0)
#define TMR_ENC_SetDigitalMode()     do { ANSELAbits. = 0; } while(0)

// get/set RA5 aliases
#define HB_LED_TRIS                 TRISAbits.TRISA5
#define HB_LED_LAT                  LATAbits.LATA5
#define HB_LED_PORT                 PORTAbits.RA5
#define HB_LED_WPU                  WPUAbits.
#define HB_LED_OD                   ODCONAbits.
#define HB_LED_ANS                  ANSELAbits.ANSA5
#define HB_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define HB_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define HB_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define HB_LED_GetValue()           PORTAbits.RA5
#define HB_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define HB_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define HB_LED_SetPullup()          do { WPUAbits. = 1; } while(0)
#define HB_LED_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define HB_LED_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define HB_LED_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define HB_LED_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define HB_LED_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB0 aliases
#define RB0_BTN_TRIS                 TRISBbits.TRISB0
#define RB0_BTN_LAT                  LATBbits.LATB0
#define RB0_BTN_PORT                 PORTBbits.RB0
#define RB0_BTN_WPU                  WPUBbits.WPUB0
#define RB0_BTN_OD                   ODCONBbits.
#define RB0_BTN_ANS                  ANSELBbits.ANSB0
#define RB0_BTN_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_BTN_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_BTN_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_BTN_GetValue()           PORTBbits.RB0
#define RB0_BTN_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_BTN_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_BTN_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_BTN_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_BTN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define RB0_BTN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define RB0_BTN_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_BTN_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 aliases
#define RB1_BTN_TRIS                 TRISBbits.TRISB1
#define RB1_BTN_LAT                  LATBbits.LATB1
#define RB1_BTN_PORT                 PORTBbits.RB1
#define RB1_BTN_WPU                  WPUBbits.WPUB1
#define RB1_BTN_OD                   ODCONBbits.
#define RB1_BTN_ANS                  ANSELBbits.ANSB1
#define RB1_BTN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_BTN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_BTN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_BTN_GetValue()           PORTBbits.RB1
#define RB1_BTN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_BTN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_BTN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_BTN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_BTN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define RB1_BTN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define RB1_BTN_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_BTN_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/