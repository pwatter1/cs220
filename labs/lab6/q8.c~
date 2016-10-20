#include <stdio.h> 
#include <stdlib.h>

struct {
	int one;
	union {
		char *uc;
		short us;
	} uni[2];
	char two, two1;
	short three;
} arr[3];

int main(){
	printf("This is &arr[0]: %x\n", &arr[0]);
	printf("This is &arr[2].three: %x\n", &arr[2].three);
	
}
