#ifndef MAIN_FUNCTIONS_H
#define	MAIN_FUNCTIONS_H

void rotate(void);
void rotate_cw(void);
void rotate_ccw(void);
void stop_rotate(void);

void get_direction(void);
void limit_steps(void);
void set_delay(void);

void Toggle_Led(void);

void UART_Initialize(void);
void UART_Command_INT(void);

#endif	/* MAIN_FUNCTIONS_H */