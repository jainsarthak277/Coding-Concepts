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
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* temp = newNode;

	head->next = newNode;
	newNode->data = array[0];
	newNode->next = NULL;
	for(int i=1; i<num_nodes; i++)
	{
		Node* nextNode = (Node*)malloc(sizeof(Node));
		nextNode->data = array[i];
		temp->next = nextNode;
		temp = nextNode;
		nextNode->next = NULL;
	}
	
	return head;
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

	head = reverse_list(head);
	if(head == NULL)
	{
		cerror("reverse_list failed; head is NULL");
	}
	print_list(head);

	head = convert_odd_even(head);
	if(head == NULL)
	{
		cerror("convert_odd_even failed; head is NULL");
	}
	print_list(head);

	return 0;
}
