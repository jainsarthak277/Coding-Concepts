#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define cerror(x) \
		{ \
			printf(x);\
			 exit(1);\
		}

#define init_list_txt		("text_files/init_list.txt")
#define remove_list_txt		("text_files/remove_list.txt")
#define sort_list1_txt		("text_files/sort_lists/sorted1.txt")
#define sort_list2_txt		("text_files/sort_lists/sorted2.txt")
#define REMOVAL_VALUE		(22)

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

int read_input(int**, char*);
Node* create_list(int, int*);
Node* copy_list(Node*, int);
void print_list(Node*);
void free_list(Node*);

Node* reverse_list(Node*);
Node* convert_odd_even(Node*);
Node* merge_alternate(Node*, Node*);
int removeNodes(Node**, int);
int findMiddle(Node*);
Node* merge_two_sorted(Node*, Node*);
int* nextLargerNodes(Node*, int*);
