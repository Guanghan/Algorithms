#include "binary_tree.h"

namespace binary_tree
{
	/* Create a new node */
	node* newNode(int data)
	{
		node* mynode = (node*)malloc(sizeof(node));
		mynode->data = data;
		mynode->left = NULL;
		mynode->right = NULL;

		return mynode;
	}

	/* Print the node using inorder */
	void printNode(node* mynode)
	{
		/* This is very important to check */
		if (mynode == NULL) return;

		printNode(mynode->left);
		printf(" %d, ", mynode->data);
		printNode(mynode->right);
	}
}