#include <stdio.h> 

int main() 
{

	const int p1 = 6;
	const int p2 = 4;
	printf("Value of p1: %x\n", p1);
	printf("Address of p1: %p\n", p1);
	int const *p1 = 9;
	printf("Value of p1 altered: %x\n", *p1);

}
