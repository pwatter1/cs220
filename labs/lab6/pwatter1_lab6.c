#include <stdio.h> 
#include <stdlib.h>


/* qustion 7 */
struct Node {
	struct Node *next;
	int val;
};

int f(struct Node *n){
	if(n == NULL) return 0;
	return 1+ f(n->next);
}

int main(){
	struct Node *head = NULL;
	head = malloc(sizeof(struct Node));
	head->val = 1;
	head->next = malloc(sizeof(struct Node));
	head->next->val = 2;
	head->next->next = malloc(sizeof(struct Node));
	head->next->next->val = 3;
	int ret = f(head);
	printf("The number of nodes in this linked list: %d\n", ret);
	
}

/* question 8 */
struct {
	int one;
	union {
		char *uc;
		short us;
	} uni[2];
	char two, two1;
	short three;
} arr[3];

int main(){
	printf("This is &arr[0]: %x\n", &arr[0]);
	printf("This is &arr[2].three: %x\n", &arr[2].three);
}

/* question 17 */
int main(){
	int i;
	int arr[] = {1,2,3,4};
	void *p = (void *) (&arr[0]);
	for(i = 0; i < 4; i++)
		printf("%d, ", *(p+i));
	return 0; 
}

/* question 36 */
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

/* question 39 */
int main(){
	int x = -0xa9;
	printf("%x\n", (unsigned int) x);
	return 0;
}

/* question 41 */
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

/* question 42 */
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

/* question 44 */
int main(){
	char a[] = {'h', 'e', 'l', 'l', 'o'};
	char *b = "hello\0";
	printf("This is strlen of a: %d\n", strlen(a));
	printf("This is strlen of b: %d\n", strlen(b));
	return 0;
}

/* question 45 */
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







