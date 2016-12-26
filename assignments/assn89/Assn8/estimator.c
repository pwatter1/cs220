#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

extern void hundred_NOP();
extern void simple_RET();

#define loops (9)
#define rotations (370000000)

int i;
int p;
long nop = 0;
long ret = 0;

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1){
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv){
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}

long compute_nop(long nop, struct timeval *tv){
	nop = nop + ((tv->tv_sec*1000000) + tv->tv_usec);
	return nop;
}
long compute_ret(long ret, struct timeval *tv){
	ret = ret + ((tv->tv_sec*1000000) + tv->tv_usec);
	return ;
}
int main(){
	struct timeval tvDiff, tvStart, tvEnd;
	for(p = 0; p < loops; p++){
		gettimeofday(&tvStart, NULL);
		for(i = 0; i < rotations; i++){ hundred_NOP();}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		nop = compute_nop(nop, &tvDiff);
		gettimeofday(&tvStart, NULL);
		for(i = 0; i < rotations; i++){ simple_RET();}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);	
		ret = compute_ret(ret, &tvDiff);
	}
	long val = ((nop - ret )/ loops);
	printf("%lld\n", rotations*100000000LL / val);
	return 0;	
}
