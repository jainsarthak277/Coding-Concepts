/*
 * File containing helper functions for List.
 * Functions are provided for Reading input from a .txt file, where .txt file has values 
 * to create Linked List from.
 * Further functions are provided for creating the list, printing the list and copying 
 * one list into another
 *
 */

#include "list.h"


int read_input(int** arr, char* filename)
{
	char c;
	int file_size = 0; 
	FILE* fp = fopen(filename, "r+");
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


/**
 * @brief Function to create a new list.
 *
 * @param num_nodes
 * @param array Takes values of nodes in array pointer
 *
 * @return head node, of which next points to first node of linked list
 */
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


void free_list(Node* head)
{
	Node *delete = head, *next = head;
	while(next != NULL)
	{
		next = delete->next;
		free(delete);
		delete = next;
	}
}


/**
 * @brief creates a copy of linked list
 *
 * @param head head pointer of list to be copied
 * @param num_nodes number of nodes in list to be copied
 *
 * @return head pointer of new list, containing copies of all values in original linked list
 */
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
//	printf("\nLinked List copied\n");
	return head_copy;
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
