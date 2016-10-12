#include <stdio.h>

int main()
{
	unsigned char* ptr = &main;
	do {
	
	printf("Value pointed to pointer as hex: %p\n", ptr);
 	printf("Main address: %p\n", &main);
	} while(*ptr != 0xc3);
} 
