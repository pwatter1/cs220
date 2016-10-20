#include <stdio.h>
#include <string.h>

int main(){
	char a[] = {'h', 'e', 'l', 'l', 'o'};
	char *b = "hello\0";
	printf("This is strlen of a: %d\n", strlen(a));
	printf("This is strlen of b: %d\n", strlen(b));
	return 0;
}
