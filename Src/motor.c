#include "motor.h"

unsigned short motor_var1 = 0x05;

void func2(void){
	motor_var1 += 5;
	//printf("motor_var1 = %i \n", motor_var1);
}


__attribute__((section(".My_custom_Section"))) void function_custom_section(void) {
	//printf("hello from my custom section \n");
	motor_var1 += 5;
}
