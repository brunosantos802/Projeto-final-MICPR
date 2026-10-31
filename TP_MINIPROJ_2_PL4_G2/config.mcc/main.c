 /*
 * MINIPROJ: P2
 * TURMA: PL4
 * GRUPO: 2
 *
 * NOME: Bruno Fernandes dos Santos
 * NUMERO: 2024114032
 *
 * NOME: Diogo Oliveira
 * NUMERO: 2242423
 */
 
 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
� [2026] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/system/system.h"

//FUNCTIONS FOR INTERRUPTS
void left_btn(void)
{
    //LED1_Toggle();
    LED3_Toggle(); //just for testing lol
}

void right_btn(void)
{
    //LED2_Toggle();
    LED3_Toggle(); //same as above, just for testing
}

//TIMER 1, HEARTBEAT AND GLOBAL VARIABLES
volatile uint8_t heartbeat_counter = 0;

void timer_1(void)
{
    heartbeat_counter++; // set heartbeat flag high so that the main loop can toggle the LED
}

void heartbeat(void)
{
    if (heartbeat_counter >= 10) // if its been 10 timer interrupts (500ms)
    {
        HB_LED_Toggle(); // toggle the heartbeat LED
        heartbeat_counter = 0; // reset the heartbeat counter
    }
}

//BUTTON PRESS FUNCTIONS
void left_button_press(void)
{
    if(RB0_BTN_GetValue())
        LED1_SetLow();
    else{
        LED1_SetHigh();
    }
}

void right_button_press(void)
{
    if(RB1_BTN_GetValue())
        LED2_SetLow();
    else{
        LED2_SetHigh();
    }
}

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    INT0_SetInterruptHandler(left_btn);
    INT1_SetInterruptHandler(right_btn);
    TMR1_OverflowCallbackRegister(timer_1);

    INTCON2bits.RBPU = 1; //set PORTB pull-ups to be disabled added manually as mentioned in class

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 


    while(1)
    {  
        heartbeat(); // call the heartbeat function to toggle the LED if the flag is set
        left_button_press(); // call the left button press function to check if the button is pressed
        right_button_press(); // call the right button press function to check if the button is pressed
    }    
}