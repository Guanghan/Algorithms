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


	/* The following methods are for BST(Binary Search Tree) */
	/* Insert new element to a binary search tree */
	node* insert(node* mynode, int key)
	{
		/* If the tree is empty, return a new node */
		if (mynode == NULL) return newNode(key);

		/* Otherwise, do recurion down in the tree */
		if (key < mynode->data)
			mynode->left = insert(mynode->left, key);
		else if (key> mynode->data)
			mynode->right = insert(mynode->right, key);

		return mynode;
	}
}