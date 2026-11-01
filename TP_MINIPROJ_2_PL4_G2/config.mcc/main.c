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


/*NOTES
    PWM ECCP1 NOTES:
        ECCP1_LoadDutyValue(0); //JUST A NOTE ON HOW TO DO THIS LATER
        0% = 0
        100% = 752

    ADC NOTES:
        0V = 0
        5V = 1023
        because the ADC varies between 0 and 3.3V
        the variable avg_adc_reading will vary between 0 and 675 (3.3/5 * 1023 = 675)
*/ 


#include "mcc_generated_files/system/system.h"

//GLOBAL VARIABLES
volatile uint8_t heartbeat_counter = 0;
volatile uint16_t avg_adc_reading = 0; //is a percentage (%)
volatile uint16_t current = 0;
volatile uint8_t adc_count = 0;

//FUNCTIONS FOR INTERRUPTS
void left_btn(void)
{
    //LED1_Toggle();
    //LED3_Toggle(); //just for testing lol
    //same as below
}

void right_btn(void)
{
    //LED2_Toggle();
    //LED3_Toggle(); //same as above, just for testing
    //does nothing freeing up debug led to test wether ADC updates
}

//TIMERS

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

//ADC FUNCTIONS

void map_adc_pwm(){
    /*
    * map the ADC reading to the PWM duty cycle
    * dividing by 675 gives a percentage
    * multiplying by 752 maps it to a PWM value the ECCP1 can use
    */
    uint32_t pwm_pct = (((uint32_t)avg_adc_reading*100)/675) * 752;
    /*
    * needed the *100 to be able to make integer divison
    * without it avg_adc_reading/675 would range between 0 and 1.
    * as an integer, i would not get the correct result, so we make it vary as a percentage from 0-100
    * and then later divide by 100 to get the correct value for the PWM duty cycle calculation.
    * granted, within reason it always drops decimals so 300.9 will be 300 not 301 but it good enough
    * the PWM duty cycle can vary between 0 and 752, so we multiply by
    * 752 to get the correct value for the PWM duty cycle
    */
    uint16_t pwm = pwm_pct/100; 
    /*
    * Clamp pwm in case there in some random error or something weird
    * noise shouldnt be an issue in proteus but if we ever have to test it on a board it might be needed
    */
    if (pwm > 752) pwm = 752; 
    if (pwm < 0) pwm = 0;
    /*
    * Load the new PWM value to the ECCP1 module
    */
    ECCP1_LoadDutyValue(pwm); // load the new PWM value to the ECCP1 module
}


void get_adc_reading(void)
{
    adc_count++;
    current += ADC_GetConversionResult();
    if (adc_count >= 5) // get the ADC reading from the potentiometer
    {
        avg_adc_reading = current / adc_count; // calculate the average ADC reading over the last 250ms
        current = 0;
        adc_count = 0;
        map_adc_pwm(); // map the ADC reading to the PWM duty cycle
        
    }
    //LED3_Toggle(); // toggle the debug LED to show that the ADC reading has been updated (Debugging purposes lol)
}

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    //Set the interrupt handlers
    INT0_SetInterruptHandler(left_btn); //Left button interrupt handler (UP)
    INT1_SetInterruptHandler(right_btn); //Right button interrupt handler (DOWN)
    TMR1_OverflowCallbackRegister(timer_1); //Timer 1 interrupt handler (heartbeat)
    ADC_SetInterruptHandler(get_adc_reading); //ADC interrupt handler (potentiometer reading)

    //Individual manual configurations
    INTCON2bits.RBPU = 1; //set PORTB pull-ups to be disabled added manually as mentioned in class
    CCPR5 = 37499; //set CCP5 compare value to 37499 for ADC reading every 50ms
    
 

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