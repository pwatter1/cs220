#include <stdio.h>
	
int main(){
	int x = 2, y=4;
	if((x = 5) || (y = 8)){
		printf("%d, %d", x, y);
		printf("\n");
	} else {
		printf("%d, %d", y, x);
		printf("\n");
	}
	return 0;
}
