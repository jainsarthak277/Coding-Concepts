#include "list.h"

int main()
{
	int* list_data = NULL;
	int num_nodes = read_input(&list_data, init_list_txt);
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


	int* remove_list_data = NULL;
	int remove_num_nodes = read_input(&remove_list_data, remove_list_txt);
	if(remove_num_nodes < 1)
	{
		cerror("read_input failed; file read has no contents")
	}

	Node* remove_head = create_list(remove_num_nodes, remove_list_data);
	if(remove_head == NULL)
	{
		cerror("create_list failed; remove_head is NULL");
	}
	printf("\nList read from 'remove_list.txt' is \n");
	print_list(remove_head);

	remove_num_nodes = removeNodes(&remove_head, REMOVAL_VALUE);
	if(remove_head == NULL)
	{
		cerror("remove_nodes failed; remove_head is NULL");
	}
	printf("%d nodes with value greater than %d removed\n", remove_num_nodes, REMOVAL_VALUE);
	print_list(remove_head);


	return 0;
}
