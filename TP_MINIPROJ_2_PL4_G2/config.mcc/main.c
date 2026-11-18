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




*/ 


#include "mcc_generated_files/system/system.h"
#include <stdio.h>

//DEFINES
#define MAX_SPEED 600
#define MAX_PWM 750 //ITS ACTUALLY 752 but were not doing all that
#define MIN_PWM 0

//GLOBAL VARIABLES
volatile uint8_t heartbeat_counter = 0; //counts the number of timer interrupts to toggle the heartbeat LED
volatile uint16_t avg_adc_reading = 0; //is a percentage (%)
volatile uint16_t current = 0; //adds up the ADC readings over 5 interrupts to get an average
volatile uint8_t adc_count = 0; //counts the number of ADC readings taken to get an average
volatile uint16_t pwm = 0; //Stores globally what the current pwm value is

//MENU FLAGS AND VARIABLES
volatile bool use_potentiometer = 1; //defines wether POT controles the motor or not [is default 1]
volatile uint8_t button_step = 10; //defines the current step in the button sequence [defined as 1/2/5/10 %] [DEFAULT 10]
volatile uint8_t increase_pwm_by_step = 75; //Related to the above variable, holds the pwm value to increase by [DEFAULT 75]
uint8_t rxData; //holds recieved data when user sends
volatile uint32_t velocidade = 0; //Stores current requested speed as per last button or pot change
char menu_select = '0'; //Stores selected menu option for menu navigation
volatile uint32_t encoder_time = 0; //stores the time it took inbetween last and 2nd to last rising edges from the encoder [IN TICKS]
volatile uint16_t encoder_speed = 0; //stores measured speed from encoder [IN RPM]
volatile uint16_t max_pwm = MAX_PWM; //speed limit to be set through menu 

//MENU FUNCTIONS
void map_step(uint8_t button_step){
    switch(button_step){
        case 1:
            increase_pwm_by_step = 7; //was really 7.52 but oh well
            break;
        case 2:
            increase_pwm_by_step = 15; //was really 15.04
            break;
        case 5:
            increase_pwm_by_step = 37; //was 37.6 
            break;
        case 10:
            increase_pwm_by_step = 75; //was 75.2
            break;
    }
}

void update_requested_speed(void){
    velocidade = ((uint32_t)MAX_SPEED*pwm)/MAX_PWM;
}

void display_main_menu(void){
    printf("\r\nMenu Inicial:");
    printf("\r\n");
    printf("\r\n1 - Desligar o motor");
    printf("\r\n2 - Selecionar controlo (potenciometro/botoes)");
    printf("\r\n3 - Definir passo dos botoes (1/2/5/10 %%)");
    printf("\r\n4 - Definir limite maximo de velocidade (50-100 %%)");
    printf("\r\n5 - Mostrar velocidade atual");
    printf("\r\n6 - Mostrar duty-cycle atual");
    printf("\r\n7 - Mostrar Log de velocidade");
}

void cursor(void){
    printf("\r\n");
    printf("\r\n0 - Voltar ao Menu Inicial");
    printf("\r\n> ");
}

void menu (void){
    if (EUSART1_IsRxReady()){
        menu_select = EUSART1_Read();
        EUSART1_Write(menu_select);
        
        switch (menu_select){
            case '0':
                EUSART1_Write(12);// clear the terminal
                display_main_menu();
                cursor();
                break;
            case '1':
                EUSART1_Write(12);
                printf("\r\nDESLIGAR O MOTOR:");
                printf("\r\n");
                printf("\r\nNOT IMPLEMENTED: MUST ADD LOGIC TO CHECK FOR CHANGE IN VARIABLES KEEPING ADC AND BUTTONS");
                cursor();
                break;
            case '2':
                EUSART1_Write(12);
                printf("\r\nMETODO DE CONTROLO:");
                printf("\r\n");
                printf("\r\nSelecione o metodo de controlo pretendido:");
                printf("\r\n1 - potenciometro");
                printf("\r\n2 - botoes");
                cursor();
                break;
            case '3':
                EUSART1_Write(12);
                printf("\r\nPASSO DOS BOTOES:");
                printf("\r\n");
                printf("\r\nSelecione o passo:");
                printf("\r\n1 - 1 %%");
                printf("\r\n2 - 2 %%");
                printf("\r\n3 - 5 %%");
                printf("\r\n4 - 10 %%");
                cursor();
                break;
            case '4':
                EUSART1_Write(12);
                printf("\r\nLIMITE VELOCIDADE:");
                printf("\r\n");
                printf("\r\nIntroduza um valor entre 50-100%%:");
                cursor();
                break;
            case '5':
                EUSART1_Write(12);
                printf("\r\nVELOCIDADE ATUAL:");
                printf("\r\n");
                printf("\r\nVelocidade: %u RPM", encoder_speed);
                cursor();
                break;
            case '6':
                EUSART1_Write(12);
                printf("\r\nDUTY CYCLE ATUAL:");
                printf("\r\n");
                float pct = (float)pwm/MAX_PWM;
                printf("\r\nDuty: %u %%", pct);
                cursor();
                break;
            case '7':
                EUSART1_Write(12);
                printf("\r\nEEPROM LOGS:");
                printf("\r\n");
                printf("\r\nNOT IMPLEMENTED YET");
                cursor();
                break;
            default:
                EUSART1_Write(12);
                printf("\r\nOpcao Invalida!");
                cursor();
                break;
        }
   
    }
}


//END MENU FUNCTIONS

//ENCODER FUNCTION
void encoder_callback(uint16_t TimerValueUS){ //calculates the time it took since the last pulse was recieved
    TMR5_CounterSet(0); //Restarts counter

    encoder_time = TimerValueUS;
}

void compute_encoder_speed(void){
    uint32_t time = encoder_time;
    if(time != 0){
        encoder_speed = 60000000UL / (time*8/3) / 24; //UL suffix tells the compiler to set it as a unsigned long (uint32_t) 
    }else{
        encoder_speed = 0;
    }
}
//END ENCODER FUNCTION

//FUNCTIONS FOR INTERRUPTS
void left_btn(void){
    if(use_potentiometer) return; // if the potentiometer is not being used, do not update the PWM value from here

    if(pwm <= max_pwm){ 
        uint16_t new_pwm = pwm;
        new_pwm += increase_pwm_by_step;
        if(new_pwm > max_pwm){new_pwm = max_pwm;}else if(new_pwm < MIN_PWM){new_pwm = MIN_PWM;}
        pwm = new_pwm;
    }

    ECCP1_LoadDutyValue(pwm); // load the new PWM value to the ECCP1 module
    update_requested_speed();
}

void right_btn(void){

    if(use_potentiometer) return; // if the potentiometer is not being used, do not update the PWM value from here

    if(pwm >= increase_pwm_by_step){
        uint16_t new_pwm = pwm;
        new_pwm -= increase_pwm_by_step;
        if(new_pwm < MIN_PWM){new_pwm = MIN_PWM;}else if(new_pwm > max_pwm){new_pwm = max_pwm;}
        pwm = new_pwm;
    }else{
        pwm = 0;
    }
    ECCP1_LoadDutyValue(pwm); // load the new PWM value to the ECCP1 module
    update_requested_speed();
}
//END INTERRUPT FUNCTIONS

//TIMERS
//TIMER 1
void timer_1(void){
    heartbeat_counter++; // set heartbeat flag high so that the main loop can toggle the LED
}

void heartbeat(void){
    if (heartbeat_counter >= 5) // if its been 5 timer interrupts (500ms)
    {
        HB_LED_Toggle(); // toggle the heartbeat LED
        heartbeat_counter = 0; // reset the heartbeat counter
    }
}
//END TIMER 1
//TIMER 5 - RPM TIMER
void tmr5_overflow(void){
    encoder_time = 0; //once compute_encoder_speed comes in it sets RPM to zero as well
}
//END TIMER 5
//END TIMERS

//BUTTON PRESS FUNCTIONS
void button_press_feedback(void){
    
    //LEFT BUTTON
    if(RB0_BTN_GetValue())
        LED1_SetLow();
    else{
        LED1_SetHigh();
    }
    
    //RIGHT BUTTON
    if(RB1_BTN_GetValue())
        LED2_SetLow();
    else{
        LED2_SetHigh();
    }
}
//END OF BUTTON PRESS FUNCTIONS


//ADC FUNCTIONS
void map_adc_pwm(void){
    if(!use_potentiometer) return; // if the potentiometer is not being used, do not update the PWM value from here
    /*
    * map the ADC reading to the PWM duty cycle
    * dividing by 675 gives a percentage
    * multiplying by 752 maps it to a PWM value the ECCP1 can use
    */
    uint32_t pwm_pct = (((uint32_t)avg_adc_reading*100)/1023) * MAX_PWM;
    /*
    * needed the *100 to be able to make integer divison
    * without it avg_adc_reading/1023 would range between 0 and 1.
    * as an integer, i would not get the correct result, so we make it vary as a percentage from 0-100
    * and then later divide by 100 to get the correct value for the PWM duty cycle calculation.
    * granted, within reason it always drops decimals so 300.9 will be 300 not 301 but it good enough
    * the PWM duty cycle can vary between 0 and 752, we discard the last 2 to keep round numbers (avoud floats as much as possible),
    * so we multiply by 750 to get the correct value for the PWM duty cycle
    */
    //global pwm value
    pwm = pwm_pct/100;
    /*
    * Clamp pwm in case there in some random error or something weird
    * noise shouldnt be an issue in proteus but if we ever have to test it on a board it might be needed
    */
    if (pwm > max_pwm) pwm = max_pwm;
    if (pwm < MIN_PWM) pwm = MIN_PWM;
    /*
    * Load the new PWM value to the ECCP1 module
    */
    ECCP1_LoadDutyValue(pwm); // load the new PWM value to the ECCP1 module
    update_requested_speed();
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

//END ADC FUNCTIONS



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
    ECCP2_SetCallBack(encoder_callback); //Every time a pulse arrives execute that function
    TMR5_OverflowCallbackRegister(tmr5_overflow);//SETS RPM TO ZERO IF 1/24th of a turn takes longer than roughly 174ms
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

    //UART MENU
    display_main_menu();
    cursor();
    while(1)
    {  
        menu(); //UART MENU
        heartbeat(); //HEARTBEAT FOR DEBUGGING
        button_press_feedback(); //VISUAL FEEDBACK FOR BUTTON PRESSES
        compute_encoder_speed(); //UPDATES REAL RPM
    }    
}