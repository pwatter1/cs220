#include <stdio.h>
int main() 
{
	int a = 0xe;
	int *b = &a;
	int **c = &b;
	int ***d = &c;
	printf("This is address of a: %p\n", a);
	printf("This is value of a: %x\n", a);
	printf("This is address of *b: %p\n", *b);
	printf("This is value of *b: %x\n", *b);
	printf("This is address of **c: %p\n", **c);
	printf("This is value of **c: %x\n", **c);
	printf("This is address of ***d: %p\n", ***d);
	printf("This is value of ***d: %x\n", ***d);
}
