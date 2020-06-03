#include "list.h"

int main()
{
/*Read Input and create linked list*/
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
/**/

/*Copy list into a new one and reverse copied list*/
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
/**/

/*Copy original list into a new one, and convert to the order of odd-even*/
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
/**/

/*Copy original list and reversed list into new lists, and merge both lists alternately*/
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
/**/

/*Read input list from remove_list.txt and remove all nodes with value greater than REMOVAL_VALUE*/
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
/**/

/*Find middle node of original linked list*/
	int middle = findMiddle(head);
	if(middle == -1)
	{
		cerror("findMiddle failed; head is NULL");
	}
	printf("\nMiddle node of Linked List has value: %d\n", middle);
/**/

/*Read input from sorted1.txt and sorted2.txt, merge the two sorted linked lists.*/
	int* sort_list1 = NULL;
	int sort_nodes1 = read_input(&sort_list1, sort_list1_txt);
	if(sort_nodes1 < 1)
	{
		cerror("read_input failed; file read has no contents")
	}

	Node* list1 = create_list(sort_nodes1, sort_list1);
	if(list1 == NULL)
	{
		cerror("create_list failed; list1_head is NULL");
	}
	printf("\nList read from 'sorted1.txt' is \n");
	print_list(list1);

	int* sort_list2 = NULL;
	int sort_nodes2 = read_input(&sort_list2, sort_list2_txt);
	if(sort_nodes2 < 1)
	{
		cerror("read_input failed; file read has no contents")
	}

	Node* list2 = create_list(sort_nodes2, sort_list2);
	if(list2 == NULL)
	{
		cerror("create_list failed; list2_head is NULL");
	}
	printf("\nList read from 'sorted2.txt' is \n");
	print_list(list2);

	Node* merge_sorted_head = merge_two_sorted(list1, list2);
	if(merge_sorted_head == NULL)
	{
		cerror("merge_two_sorted failed; merge_sorted_head is NULL");
	}
	print_list(merge_sorted_head);
/**/

/*Find array of next larger nodes of Merged sorted linked list*/
	int *retArray = NULL, *retSize = (int *)malloc(sizeof(int));
	printf("\n");
	print_list(merge_sorted_head);
	retArray = nextLargerNodes(merge_sorted_head, retSize);
	printf("Array of Next Larger Nodes is: [");
	for(int i=0; i<*retSize; i++)
	{
		printf("%d ", retArray[i]);
	}
	printf("]\n");
/**/

	free_list(head_rev);

	return 0;
}
