#include <stdio.h>
#include <stdlib.h>

struct _Node {
	union {
		int n;
		char c;
	} val;
	void *ptr;
	int var;
};
typedef struct _Node Node;

Node *change_address(void *ptr);

/* Create new linked list, reverse it by switching addresses and values */
Node *my_reverse(Node *head){
	Node *prev = NULL;
	Node *last_node = malloc(sizeof(Node));
	Node *other_node;
	Node *temp = head;
	if(head == NULL){ return NULL;}
	/* if linked list with single value, return list */
	if(temp->ptr == NULL){ return temp;}
	/* CANNOT GET CORRECT WHEN LIST IS NULL ?? */
	/* if list is NULL, return NULL */

	else{
		while((temp->ptr) != NULL){	
			/* if end of original list */
			if(prev == NULL){
				last_node->ptr = malloc(sizeof(Node));
				last_node->val = temp->val;
				last_node->var = temp->var;
				last_node->ptr = NULL;
			}else{ 
				last_node->ptr = malloc(sizeof(Node));
				last_node->val = temp->val;
				last_node->var = temp->var;
				last_node->ptr = (&(prev->ptr) - 0x8);
			}
			prev = last_node;
			temp = (Node *) ((temp->ptr) - 0x8);
		}

		/* get rid of weird repeat by deleting first link */
		temp = last_node;
		last_node = (Node *) ((last_node->ptr) - 0x8);
		free(temp);
		
		/* return reversed list */
		return last_node;
	}
}
