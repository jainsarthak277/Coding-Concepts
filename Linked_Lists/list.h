#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define cerror(x) \
		{ \
			printf(x);\
			 exit(1);\
		}

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

int read_input(int**);

Node* create_list(int, int*);
Node* reverse_list(Node*);
void print_list(Node*);
