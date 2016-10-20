#include <stdio.h>

int main(){
	int i;
	int arr[] = {1,2,3,4};
	void *p = (void *) (&arr[0]);
	for(i = 0; i < 4; i++)
		printf("%d, ", *(p+i));
	return 0; 
}
