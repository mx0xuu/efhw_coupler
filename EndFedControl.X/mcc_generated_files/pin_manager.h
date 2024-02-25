/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18444
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set O_LED aliases
#define O_LED_TRIS                 TRISBbits.TRISB6
#define O_LED_LAT                  LATBbits.LATB6
#define O_LED_PORT                 PORTBbits.RB6
#define O_LED_WPU                  WPUBbits.WPUB6
#define O_LED_OD                   ODCONBbits.ODCB6
#define O_LED_ANS                  ANSELBbits.ANSB6
#define O_LED_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define O_LED_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define O_LED_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define O_LED_GetValue()           PORTBbits.RB6
#define O_LED_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define O_LED_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define O_LED_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define O_LED_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define O_LED_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define O_LED_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define O_LED_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define O_LED_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set O_IN1 aliases
#define O_IN1_TRIS                 TRISCbits.TRISC0
#define O_IN1_LAT                  LATCbits.LATC0
#define O_IN1_PORT                 PORTCbits.RC0
#define O_IN1_WPU                  WPUCbits.WPUC0
#define O_IN1_OD                   ODCONCbits.ODCC0
#define O_IN1_ANS                  ANSELCbits.ANSC0
#define O_IN1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define O_IN1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define O_IN1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define O_IN1_GetValue()           PORTCbits.RC0
#define O_IN1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define O_IN1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define O_IN1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define O_IN1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define O_IN1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define O_IN1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define O_IN1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define O_IN1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set O_IN2 aliases
#define O_IN2_TRIS                 TRISCbits.TRISC1
#define O_IN2_LAT                  LATCbits.LATC1
#define O_IN2_PORT                 PORTCbits.RC1
#define O_IN2_WPU                  WPUCbits.WPUC1
#define O_IN2_OD                   ODCONCbits.ODCC1
#define O_IN2_ANS                  ANSELCbits.ANSC1
#define O_IN2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define O_IN2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define O_IN2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define O_IN2_GetValue()           PORTCbits.RC1
#define O_IN2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define O_IN2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define O_IN2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define O_IN2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define O_IN2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define O_IN2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define O_IN2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define O_IN2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set O_IN3 aliases
#define O_IN3_TRIS                 TRISCbits.TRISC2
#define O_IN3_LAT                  LATCbits.LATC2
#define O_IN3_PORT                 PORTCbits.RC2
#define O_IN3_WPU                  WPUCbits.WPUC2
#define O_IN3_OD                   ODCONCbits.ODCC2
#define O_IN3_ANS                  ANSELCbits.ANSC2
#define O_IN3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define O_IN3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define O_IN3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define O_IN3_GetValue()           PORTCbits.RC2
#define O_IN3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define O_IN3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define O_IN3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define O_IN3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define O_IN3_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define O_IN3_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define O_IN3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define O_IN3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set O_IN4 aliases
#define O_IN4_TRIS                 TRISCbits.TRISC3
#define O_IN4_LAT                  LATCbits.LATC3
#define O_IN4_PORT                 PORTCbits.RC3
#define O_IN4_WPU                  WPUCbits.WPUC3
#define O_IN4_OD                   ODCONCbits.ODCC3
#define O_IN4_ANS                  ANSELCbits.ANSC3
#define O_IN4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define O_IN4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define O_IN4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define O_IN4_GetValue()           PORTCbits.RC3
#define O_IN4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define O_IN4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define O_IN4_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define O_IN4_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define O_IN4_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define O_IN4_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define O_IN4_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define O_IN4_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set I_BTN_R aliases
#define I_BTN_R_TRIS                 TRISCbits.TRISC4
#define I_BTN_R_LAT                  LATCbits.LATC4
#define I_BTN_R_PORT                 PORTCbits.RC4
#define I_BTN_R_WPU                  WPUCbits.WPUC4
#define I_BTN_R_OD                   ODCONCbits.ODCC4
#define I_BTN_R_ANS                  ANSELCbits.ANSC4
#define I_BTN_R_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define I_BTN_R_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define I_BTN_R_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define I_BTN_R_GetValue()           PORTCbits.RC4
#define I_BTN_R_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define I_BTN_R_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define I_BTN_R_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define I_BTN_R_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define I_BTN_R_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define I_BTN_R_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define I_BTN_R_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define I_BTN_R_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set I_BTN_L aliases
#define I_BTN_L_TRIS                 TRISCbits.TRISC5
#define I_BTN_L_LAT                  LATCbits.LATC5
#define I_BTN_L_PORT                 PORTCbits.RC5
#define I_BTN_L_WPU                  WPUCbits.WPUC5
#define I_BTN_L_OD                   ODCONCbits.ODCC5
#define I_BTN_L_ANS                  ANSELCbits.ANSC5
#define I_BTN_L_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define I_BTN_L_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define I_BTN_L_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define I_BTN_L_GetValue()           PORTCbits.RC5
#define I_BTN_L_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define I_BTN_L_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define I_BTN_L_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define I_BTN_L_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define I_BTN_L_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define I_BTN_L_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define I_BTN_L_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define I_BTN_L_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/