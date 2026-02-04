#ifndef _APP_H_
#define _APP_H_


int add_two_number(int num1, int num2);			// function prototype
extern void func2(void);						// extern function prototype declared in another file (motor.c)
extern void function_custom_section(void);
extern unsigned int motor_var1;					// extern variable declared in another file (motor.c)


#endif