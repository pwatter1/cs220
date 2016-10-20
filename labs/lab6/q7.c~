#include <stdio.h> 
#include <stdlib.h>

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

