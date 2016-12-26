#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fcntl.h>
#include <malloc.h>

#define BIT(n) (1 << (n))
#define BIT_SET(v, mask) (v |= (mask))
#define BIT_CLEAR(v, mask) (v &= ~(mask))
#define BIT_FLIP(v, mask) (v ^= (mask))
#define IS_SET_ANY (v & (mask))
#define IS_CLEAR_ANY (v & ~(mask))

#define BIT_MASK(len) (BIT(len) - 1)
#define BF_MASK(start, len) (BIT_MASK(len) << (start)) /* create bitfield mask of length starting at start */
#define BF_PREP(x, start, len) (((x) & BIT_MASK(len)) << (start)) /* prepare a bitmask for insertion */

#define BF_GET(y, start, len) (((y) >> (start)) & BIT_MASK(len))
#define BF_SET(y, x, start, len) (y = ((y) &~ BF_MASK(start, len)) | BF_PREP(x, start, len))

struct timeval tvDiff, tvStart, tvEnd;

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1){
	long int diff = (t2->tv_usec + 1000000 * t2->tv_sec)-(t1->tv_usec + 1000000 * t1->tv_sec);
	result->tv_sec = diff / 1000000;
	result->tv_usec = diff % 1000000;
	return (diff<0);
}

void timeval_print(char *str, struct timeval *tv){
	printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}

unsigned int get_page_offset(unsigned int address){
	return BF_GET(address, 0, 11);
}

unsigned int get_tlb_id(unsigned int address){
	return BF_GET(address, 12, 3);
}

unsigned int get_tlb_tag(unsigned int address){
	return BF_GET(address, 24, 8);
}

unsigned int set_page_offset(unsigned int address, unsigned int new_offset){
	return BF_SET(address, new_offset, 0, 11);
}

unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
	return BF_SET(address, new_tlb_id, 12, 3);
}

unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
	return BF_SET(address, new_tag, 24, 8);
}

void print_in_binary(unsigned int x)
{
	int i;
	for(i = 31; i >= 0; i--){
		if(x & (1 << i)) printf("1");
		else printf("0");
	}	
	printf("\n");
}

int main()
{
	unsigned int address = 0xf712c0d0;
	print_in_binary(address);
	unsigned int q = set_tlb_tag(address, 0x84);
	print_in_binary(q);	
	return 0;

}
