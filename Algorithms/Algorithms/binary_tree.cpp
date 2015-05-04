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
		else
		{
			printNode(mynode->left);
			printf(" %d, ", mynode->data);
			printNode(mynode->right);
		}
	}


	/*------ The following methods are for BST(Binary Search Tree)---- */
	/* Insert new element to a binary search tree */
	node* bstInsert(node* mynode, int key)
	{
		/* If the tree is empty, return a new node */
		if (mynode == NULL) return newNode(key);

		/* Otherwise, do recurion down in the tree */
		if (key < mynode->data)
			mynode->left = bstInsert(mynode->left, key);
		else if (key> mynode->data)
			mynode->right = bstInsert(mynode->right, key);

		return mynode;
	}

	/* Utility method: find the minimum value node when it is not empty. No search is needed */
	node* minValueNode(node* mynode)
	{
		node* temp = mynode;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}

		return temp;
	}

	/* Delete element from a binary search tree */
	// Note: Draw a graph for each situation helps thinking this out.
	node* bstDelete(node* root, int key)
	{
		// Base case
		if (root == NULL)
		{
			//printf("Warning in binary_tree::bstDelete(node* mynode, int key): tree is empty, nothing to delete\n");
			return root;
		}

		// Do recursion, see if the key to be deleted is on the left or right
		if (key < root->data)
			root->left= bstDelete(root->left, key);
		else if (key > root->data)
			root->right= bstDelete(root->right, key);
		else
		{
			/* When the node to be deleted has no child*/
			/* When the node to be deleted has one child */
			if (root->left == NULL)
			{
				node* temp = root->right;
				free(root);

				return temp;
			}
			else if (root->right == NULL)
			{
				node* temp = root->left;
				free(root);

				return temp;
			}

			/* When the node to be deleted has two children */
			// Get the inorder successor, the smallest in the right subtree
			node* temp = minValueNode(root->right);
			// Copy the content of the inorder successor to this node
			root->data = temp->data;
			// Delete the successor using recursion function
			root->right = bstDelete(root->right, temp->data);
		}

		return root;	//The position of this line is quite important.
	}



}