/*
 * File:   newmain.c
 * Author: RG
 *
 * Created on 15 August 2021, 18:44
 */
// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = HFINT1  // Power-up default value for COSC bits (HFINTOSC (1MHz))
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = OFF      // Master Clear Enable bit (MCLR pin function is port defined function)
#pragma config PWRTS = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config BBSIZE = BB512   // Boot Block Size Selection bits (512 words boot block size)
#pragma config BBEN = OFF       // Boot Block Enable bit (Boot Block disabled)
#pragma config SAFEN = OFF      // SAF Enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block Write Protection bit (Application Block not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration Register not write protected)
#pragma config WRTD = OFF       // Data EEPROM write protection bit (Data EEPROM NOT write protected)
#pragma config WRTSAF = OFF     // Storage Area Flash Write Protection bit (SAF not write protected)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (High Voltage on MCLR/Vpp must be used for programming)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (UserNVM code protection disabled)


#include <xc.h>
// Set Frequency
#define _XTAL_FREQ 8000000          // 8 Mhz

// Define the Control pins
#define led_red RB7                 // Led on Pin 10
#define IN1 RC0                     // Stepper IN4 Pin 16
#define IN2 RC1                     // Stepper IN3 Pin 15
#define IN3 RC2                     // Stepper IN2 Pin 14
#define IN4 RC3                     // Stepper IN1 Pin 7
#define dir_CW  RC5                 // Dir = CW Pin 5
#define dir_CCW RC4                 // Dir = CCW Pin 6

int gSteps = 0;
int gDelay = 8;
unsigned char gDirection = 0;       //0=CW, 1=CCW
// Stepper motor phase 
unsigned int gPhase_1[8] = {0,0,0,0,0,1,1,1,0};
unsigned int gPhase_2[8] = {0,0,0,1,1,1,0,0,0};
unsigned int gPhase_3[8] = {0,1,1,1,0,0,0,0,0};
unsigned int gPhase_4[8] = {1,1,0,0,0,0,0,1,0};

void blink()
{
    led_red = 1;
    __delay_us(50000);
    led_red = 0;
    __delay_us(50000);
}

void rotate1(int step_val)
{
    IN1 = gPhase_1[step_val];
    IN2 = gPhase_2[step_val];
    IN3 = gPhase_3[step_val];
    IN4 = gPhase_4[step_val];
}

void get_direction()
{
    if (dir_CW == 0) {
        gDirection = 0;
    } 
    if (dir_CCW == 0) {
        gDirection = 1;
    }
}

void set_direction()
{
    if (gDirection == 1) {    // CCW
        gSteps++;
    } 
   if (gDirection == 0) {     //CW
        gSteps--;
    }
    if (gSteps > 7){
        gSteps = 0;
    }
    if (gSteps < 0) {
        gSteps = 7;
    }

}

void get_delay()
{
    if (dir_CW == 0) {
        gDelay = 8;    
    }
    
    if (dir_CCW == 0) {
        gDelay = 80;                    
    }
}

void set_delay()
{
    int i = 0;
    while (i < gDelay) {
        __delay_us(100);
        i++;
    }  
    
}

void setup(void)
{
    OSCCON1 = 0b01100000;               //HFINTOSC (No PLL)
    OSCFRQ = 0b00000011;                //8 Mhz 
    ANSELA = 0;                         // All digital I/O
    ANSELB = 0;
    ANSELC = 0;
    TRISA = 0b00000000;                 // Set PORT I/O - all output
    TRISB = 0b00000000;                 // Set PORT I/O - all output
    TRISC = 0b00110000;                 // Set PORT I/O - 4 and 5 are input
    IN1 = 0;
    IN2 = 0;
    IN3 = 0;
    IN4 = 0;
}

void main(void)
{
    setup();                            // Setup
    for (;;)
    { 
        //get_direction();
        get_delay();
        set_direction();
        rotate1(gSteps);
        set_delay();
        
    }
    return;
}
