#include <stdio.h>

struct _Node {
	struct _Node *next;
	struct _Node *prev;
};
typedef struct _Node Node;

Node *sort_nodes(Node *head);
void trade(Node *node1, Node *node2);
Node *find_max(Node *begin);

/*
Node *remove_node(Node *n);
int insert_after(Node *what, Node *where);
Node *create();
int find_length(Node *head);
void print_list(Node *head);
*/

