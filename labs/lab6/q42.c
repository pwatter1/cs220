#include <stdio.h>
	
int main(){
	int x = 2, y = 4;
	if(x == 1)
		if(y == 2)
			x = 6;
	else 
		y = 9;
	
	printf("x = %d, y = %d \n", x, y);
	return 0;
}
