#include <stdio.h>
#include <stdlib.h>

int main()
{
int i = 0;
for(i; i<100000000; i++){
	int*p = (int *) malloc (i * 0x1000);
	if(p != NULL) {
	*p = 10; /* right before else */
	} else {
		printf("Malloc failed!\n");
	}
}

return 0;
}
