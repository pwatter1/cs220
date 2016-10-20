#include <stdio.h>

int main(){
	void *p;
	int *i;
	char *c;
	p = 0;
	i = (int *) p;
	i += 2;
	c = (char *) i;
	c += 5;
	p = (void *)c;
	printf("%u\n", (unsigned int) p);
	return 0;
}
