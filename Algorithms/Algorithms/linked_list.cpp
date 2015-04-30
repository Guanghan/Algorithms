#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* push the new data to the very front */
void pushFront(node** head_ref, int new_data)
{
	/* 1. Create a new node*/
	node* new_node = (node*)malloc(sizeof(node));

	/* 2. For the new node: assign the new data as its value */
	new_node->data = new_data;
	
	/* 3. For the new node: assign the original head node as its next node */
	new_node->next_node = *head_ref;

	/* 4. For the linked list: update its head reference */
	*head_ref = new_node;

}

/* insert the new data after the previous node */
void insertAfter(node* prev_node, int new_data)
{
	/* 0. Check if given prev_node is NULL */
	if (prev_node == NULL)
	{
		printf("function [insertAfter] error: 1st parameter prev_node can't be NULL\n");
		return;
	}

	/* 1. Create a new node */
	node* new_node = (node*)malloc(sizeof(node));

	/* 2. For the new node: assign new data as the value*/
	new_node->data = new_data;

	/* 3. For the new node: the next node will be previous node's next node */
	new_node->next_node = prev_node->next_node;

	/* 4. For the previous node: the next node will be the new node */
	prev_node->next_node = new_node;

}

/* append the new data to the very end */
void appendEnd(node ** head_ref, int new_data)
{
	/* 1. Create a new node */
	node* new_node = (node*)malloc(sizeof(node));

	/* 2. Assign the value for the new_node */
	new_node->data = new_data;

	/* 3. The new node should be the last node */
	new_node->next_node = NULL;
	
	/* 4. Check whether the linked list was NULL */
	if ((*head_ref) == NULL)
	{
		*head_ref = new_node; //make the new node the head node
		return;
	}

	/* 5. Find the last node before appending */
	node* last_node = *head_ref;
	while (last_node->next_node != NULL)
	{
		last_node = last_node->next_node;
	}

	/* 6. update the last node: add the new node after it */
	last_node->next_node = new_node;

}

/* print out the nodes of the list */
void printLinkedList(node* mynode)
{
	while (mynode != NULL)
	{
		printf("%d ", mynode->data);
		mynode= mynode->next_node;
	}
	printf("\n");
}

/*
Tips:
1. It is easy to forget procedure [0] in function [insertAfter]
2. It is easy to forget procedure [4] in function [appendEnd]
*/