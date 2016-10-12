#include <stdio.h>
#include "secret.h"

unsigned int extract_secret(struct secret_keeper *);

int main()
{
	struct secret_keeper *k;
	unsigned int secret;
	k = get_keeper();
	secret = extract_secret(k);
	printf("Secret is %s\n", verify_secret(secret) == 1 ?  "correct" : "wrong");
	return 0;
}

unsigned int extract_secret(struct secret_keeper *k)
{	
	void* temp = k->ptr;
	int i = 0;
	for(i; i < k->count; i++){
		temp = ((union secret *) temp)->ptr;	
	}
	unsigned long val = (unsigned long) temp;
	printf("%d\n", val);
	return val;
}

