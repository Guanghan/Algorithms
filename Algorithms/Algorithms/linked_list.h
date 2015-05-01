struct node
{
	int data;
	node* next_node;
};

/* push the new data to the very front */
void pushFront(node** head_ref, int new_data);

/* insert the new data after the previous node */
void insertAfter(node* prev_node, int new_data);

/* append the new data to the very end */
void appendEnd(node ** head_ref, int new_data);

/* print out the nodes of the list */
void printLinkedList(node* mynode);

/* Delete the earliest node that holds the give data */
void deleteNode(node** head_ref, int key);

/* Delete the node with given pointr */
void deleteNode(node* node_ptr);

/* Delete the whole linked list */
void deleteList(node** head_ref);

/* Get the Nth node in the linked list */
node* getNthNode(node** head_ref, int N);