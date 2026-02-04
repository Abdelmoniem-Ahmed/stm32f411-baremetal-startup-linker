#include <stdio.h>
#include "app.h"

unsigned int app_var_bss;						// uninitialized global variable stored in .bss section
unsigned int app_var1 = 0x55;					// initialized global variable stored in .data section
static unsigned short app_var2 = 0x11;			// initialized static global variable stored in .data section
const unsigned char operation = '+';			// initialized constant global variable stored in .rodata section


int main() {


	/*printf("Number One = %i \n", app_var1);
	printf("Number two = %i \n", app_var2);
	printf("Operation  = %c \n", operation);
	printf("extern_var = %i \n", motor_var1);*/

	app_var_bss = add_two_number(app_var1, app_var2);

	/*printf("Number One = %i \n", app_var1);
	printf("Number two = %i \n", app_var2);
	printf("Operation  = %c \n", operation);
	printf("extern_var = %i \n", motor_var1);
	printf("app_var_bss = %i \n", app_var_bss);*/
	func2();

	function_custom_section();

	while (1)
	{

	}

	return 0;

}


int add_two_number(int num1, int num2) {
	unsigned int l_temp = 0;
	l_temp = num1 + num2;
	return l_temp;
}

