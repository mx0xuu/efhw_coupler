/*
 * File:   mainfunctions.c
 * Author: User
 *
 * Created on August 20, 2021, 3:30 PM
 */
#include "mainfunctions.h"
#include "mcc_generated_files/mcc.h"

// Stepper Steps
int gSteps = 0;
// Delay Min 100uS
int gDelay = 10;
// Direction
int gDirection = 0;
// Stepper motor phase 
unsigned int gPhase_1[9] = {0, 0, 0, 0, 0, 1, 1, 1, 0};
unsigned int gPhase_2[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
unsigned int gPhase_3[9] = {0, 1, 1, 1, 0, 0, 0, 0, 0};
unsigned int gPhase_4[9] = {1, 1, 0, 0, 0, 0, 0, 1, 0};
//User command received
volatile uint8_t rxData;

void rotate(void)
{
    O_IN1_PORT = gPhase_1[gSteps];
    O_IN2_PORT = gPhase_2[gSteps];
    O_IN3_PORT = gPhase_3[gSteps];
    O_IN4_PORT = gPhase_4[gSteps];
}

// Rotate CCW
void rotate_ccw(void)
{   //CCW
    rotate();
    gSteps++;
    limit_steps();
    set_delay();
}

// Rotate CW 
void rotate_cw(void)
{   //CW
    rotate();
    gSteps--;
    limit_steps();
    set_delay();
}

// Stop Rotation  
void stop_rotate(void)
{   //CW
    gSteps = 9;
    rotate();
}


void get_direction(void)
{
    switch (gDirection)
    {
        case 0:
        {
            stop_rotate();
            break;
        }
        
        case 1:
        {
            rotate_cw();
            break;
        }
    
        case 2:
        {
            rotate_ccw();
            break;
        }
        
        default:
        {
            stop_rotate();
            break;
        }
    }
    
}

void limit_steps(void)
{
    if (gSteps > 7)
    {
        gSteps = 0;
    }
    if (gSteps < 0)
    {
        gSteps = 7;
    }
}

void set_delay(void)
{
    int i = 0;
    while (i < gDelay)
    {
        __delay_us(100);
        i++;
    }
}

void Toggle_Led(void)
{
    O_LED_Toggle();
    __delay_ms(200);
    O_LED_Toggle();
    __delay_ms(200);
}

void UART_Initialize(void)
{
    printf("\n");
    printf("E n d f e d - S e r i a l - C o n t r o l\r\n\n");
    printf("Type U : Clock Wise \r\n");
    printf("Type D : Counter Clock Wise \r\n");
    printf("Type F : Fast Tune \r\n");
    printf("Type S : Slow Tune \r\n");
    printf("Type X : Stop Tune \r\n");
    printf("Type ? : See this again \r\n");
    printf("------------------------\r\n");
}

void UART_Command_INT()
{
    if (EUSART1_is_rx_ready())
    {
        rxData = EUSART1_Read(); // read a byte for RX
        //EUSART1_Write(rxData); // send a byte to TX  (from Rx)        
        switch (rxData) // check command  
        {
        case '?':
        {
            UART_Initialize();
            break;
        }
        case 'D':
        case 'd':
        {
            gDirection = 2; 
            printf(" -> CCW. \r");
            break;
        }
        case 'U':
        case 'u':
        {
            gDirection = 1;
            printf(" -> CW.  \r");
            break;
        }
        case 'S':
        case 's':
        {
            gDelay = 80;
            printf(" -> Slow.  \r");
            break;
        }
        case 'F':
        case 'f':
        {
            gDelay = 10;
            printf(" -> Fast.  \r");
            break;
        }
        case 'X':
        case 'x':
        {
            gDirection = 0;
            printf(" -> Stop.  \r");
            break;                    
        }
            
        default:
        {
            printf(" -> Fail Command!! \r");
            break;
        }
        }
    }
}
