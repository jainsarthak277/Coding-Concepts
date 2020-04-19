/*
 * Program to demonstrate basic Linked List with create, 
 * insert, delete and display functions.
 *
 * Scope for a lot more functions.
 */

#include "list.h"


int read_input(int** arr)
{
	char c;
	int file_size = 0; 
	FILE* fp = fopen("init_list.txt", "r+");
	for(c=getc(fp); c!=EOF; c=getc(fp))
	{
		if(c == '\n')
		{
			file_size++;
		}
	}
	fseek(fp, 0, SEEK_SET);
	
	*arr = (int*)malloc(sizeof(int) * file_size);
	for(int i=0; i<file_size; i++)
	{
		fscanf(fp, "%d", &*(*arr+i));
	}
	fclose(fp);
	fp = NULL;
	return file_size;
}


Node* create_list(int num_nodes, int* array)
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* temp = head;

	for(int i=0; i<num_nodes; i++)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = array[i];
		temp->next = newNode;
		temp = newNode;
		newNode->next = NULL;
	}
	
	return head;
}


Node* copy_list(Node* head, int num_nodes)
{
	Node* head_copy = (Node*)malloc(sizeof(Node));
	Node* traverse = head_copy;
	head = head->next;
	for(int i=0; i<num_nodes; i++)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = head->data;
		traverse->next = newNode;

		traverse = newNode;
		newNode->next = NULL;
		head = head->next;
	}
	printf("\nLinked List copied\n");
	return head_copy;
}


Node* reverse_list(Node* head)
{
	Node* curr = head->next;
	Node* next = NULL;
	Node* prev = NULL;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head->next = prev;
	printf("\nLinked List reversed\n");
	curr = NULL;
	prev = NULL;
	next = NULL;
	return head;
}


Node* convert_odd_even(Node* head)
{
	if((head == NULL) || (head->next == NULL) || (head->next->next == NULL))
	{
		return head;
	}

	Node* odd = head->next;	
	Node* even = odd->next;	
	Node* even_backup = even;
	while((even != NULL) && (even->next != NULL))
	{
		odd->next = odd->next->next;
		odd = odd->next;
		even->next = even->next->next;
		even = even->next;
	}
	odd->next = even_backup;
	printf("\nLinked List converted to the order odd->even\n");
	return head;
}

Node* merge_alternate(Node* headA, Node* headB)
{
	if(headA == NULL || headA->next == NULL)
	{
		return headA;
	}
	if(headB == NULL || headB->next == NULL)
	{
		return headB;
	}

	Node* head_ref = (Node*)malloc(sizeof(Node));

	head_ref->next = headA->next;
	Node* tempA = NULL;
	Node* tempB = NULL;
	headA = headA->next;
	headB = headB->next;
	while((headA->next != NULL) && (headB->next != NULL))
	{
		tempA = headA->next;
		headA->next = headB;
		tempB = headB->next;
		headB->next = tempA;

		headA = tempA;
		headB = tempB;
	}

	if(headA->next == NULL)
	{
		headA->next = headB;
		headB->next = NULL;
	}
	else if(headB->next == NULL)
	{
		headB->next = headA;
		headA->next = NULL;
	}
	printf("\nTwo Linked Lists merged alternately\n");
	return head_ref;
}


void print_list(Node* head)
{
	int num_nodes = 0;
	Node* temp;
	temp = head;
	printf("Linked List is: \n");
	while(temp->next != NULL)
	{
		temp = temp->next;
		num_nodes++;
		printf("Node %d: Data %d\n", num_nodes, temp->data);
	}
}


int main()
{
	int* list_data = NULL;
	int num_nodes = read_input(&list_data);
	if(num_nodes < 1)
	{
		cerror("read_input failed; file read has no contents")
	}
	

	Node* head = create_list(num_nodes, list_data);
	if(head == NULL)
	{
		cerror("create_list failed; head is NULL");
	}
	print_list(head);


	Node* head_rev = copy_list(head, num_nodes);
	if(head_rev == NULL)
	{
		cerror("copy_list failed; head is NULL");
	}
	head_rev = reverse_list(head_rev);
	if(head_rev == NULL)
	{
		cerror("reverse_list failed; head is NULL");
	}
	print_list(head_rev);


	Node* head_odd_even = copy_list(head, num_nodes);
	if(head_odd_even == NULL)
	{
		cerror("copy_list failed; head is NULL");
	}
	head_odd_even = convert_odd_even(head_odd_even);
	if(head_odd_even == NULL)
	{
		cerror("convert_odd_even failed; head is NULL");
	}
	print_list(head_odd_even);


	Node* head_A = copy_list(head, num_nodes);
	Node* head_B = copy_list(head_rev, num_nodes);
	if((head_A == NULL) || (head_B == NULL))
	{
		cerror("copy_list failed; head is NULL");
	}
	Node* head_merge = merge_alternate(head_A, head_B);
	if(head_merge == NULL)
	{
		cerror("alternate merge failed; head is NULL");
	}
	print_list(head_merge);


	return 0;
}
