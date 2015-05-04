#include <stdio.h>
#include <stdlib.h>

namespace binary_tree
{
	struct node
	{
		int data;
		node* left;
		node* right;
	};

	/* Create a new node */
	node* newNode(int data);

	/* Print the node using inorder */
	void printNode(node* mynode);

	/* Insert new element to a binary search tree */
	node* insert(node* mynode, int key);
}