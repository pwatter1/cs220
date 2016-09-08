#include "prog.h"


int nthFib(int n)
{
	/* Question 1: Implement function. */

	int val = 0;
	int first = 0; int second = 1;
	int i = 0;
	if(n < 1 || n > 30){return -1;}
	for(i; i <= n; i++){
		if(i <= 1){
			val = i;
		}else{
			val = first + second;
			first = second;
			second = val;	
		}
	}
	return val; 
}

int asq_minus_bsq(int a, int b) 
{
	/* Question 2: Implement function. */
	return ((a*a)-(b*b));
}

