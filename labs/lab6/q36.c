#include <stdio.h>
	
unsigned int foo(unsigned int n){
	int ret = n % 10;
	while (n /= 10){
		ret *= 10;
		ret += n % 10;
	}
	return ret;
}

int main(){
	unsigned int forward = 123456789;
	unsigned int reverse = foo(forward);
	printf("This is the original number: %d\n", forward);
	printf("This is the reverse: %d\n", reverse);
	return 0;
}
