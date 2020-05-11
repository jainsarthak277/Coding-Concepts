/*
 * Program to demonstrate Linked List functionalities like 
 * reversal, odd-even conversion and alternate merge.
 *
 * Scope for a lot more functions.
 */

#include "list.h"


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


/**
 * @brief converts linked list into a list arranged as all odd-indexed nodes followed by all even-indexed nodes
 * Eg. Original list: 10->20->30->40->50; Converted list: 10->30->50->20->40.
 *
 * @param head
 *
 * @return 
 */
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


/**
 * @brief Merges two linked lists in an alternate fashion ie. Node1 of listA followed by Node1 of listB followed by Node2 of listA and so on.
 *
 * @param headA
 * @param headB
 *
 * @return 
 */
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

int removeNodes(Node** head, int x)
{
	Node* temp = *head;
	Node* prev = *head;
	int removed = 0;
	if(*head == NULL)
	{
		return 0;
	}
	temp = temp->next;
	while((temp != NULL) && (!(temp->data <= x)))
	{
//		printf("Temp value loop : %d\n", temp->data);

		*head = temp->next;
		temp = temp->next;
		prev = *head;
		removed++;
	}
	if(temp == NULL)
	{
		return removed;
	}
	temp = temp->next;
	while(temp != NULL)
	{
		if(x < temp->data)
		{
//			printf("Temp value : %d\n", temp->data);
			prev->next = temp->next;
			removed++;
		}
		else
		{
			prev = temp;
		}
		temp = temp->next;
	}
	return removed;
}


int findMiddle(Node* head)
{
	if((head == NULL) || (head->next == NULL))
	{
		return -1;
	}
	Node* slow = head, *fast = head;
	while((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}
