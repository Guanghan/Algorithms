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
	node* bstInsert(node* mynode, int key);

	/* Utility method: find the minimum value node when it is not empty. No search is needed */
	node* minValueNode(node* mynode);

	/* Delete element from a binary search tree */
	node* bstDelete(node* mynode, int key);
}