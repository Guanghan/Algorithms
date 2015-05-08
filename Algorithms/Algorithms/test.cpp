#include <stdio.h>
#include <iostream>
#include "test.h"

//#define MERGE_SORT
//#define INSERTION_SORT
#define  QUICK_SORT
#define  LINKED_LIST
#define  STACK
#define  QUEUE
#define  BINARY_TREE
#define  HEAP

int main( int argc, char** argv )
{
	/* 1. Test algorithms */
	printf("[TESTING ALGORITHMS]\n");

	float Array[] = { 23, 42, 54, 11, 32, 44, 76, 18, 23, 52, 31, 22, 10, 7, 21, 33, 23 };
	float *Sorted = (float*)malloc(sizeof(Array));
	float key = Array[1];

	printf("\n");
	for (int i = 0; i< sizeof(Array) / sizeof(float); i++){
		printf("Array[%d]= %f\n", i, Array[i]);
	} printf("\n");

#ifdef INSERTION_SORT
	printf("TEST OF INSERTION SORT\n");

	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float);

	insertion_sort(A, N);
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
             printf("Array[%d]= %f\n", i, Array[i]);  
	}

	system("pause");
	printf("\n");
#endif

#ifdef MERGE_SORT
	printf("TEST OF MERGE SORT\n");

	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float); printf("N= %d\n", N);

	merge_sort(A, 1, 17);   printf("Merge finish\n");
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
       printf("Array[%d]= %f\n", i, Array[i]); 
	}
#endif

#ifdef QUICK_SORT
	printf("TEST OF QUICK SORT\n");

	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float);

	quick_sort(Array, 1, 17);
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
       printf("Array[%d]= %f\n", i, Array[i]); 
	}

	system("pause");
	printf("\n");
#endif
	
	printf("-------------------------------------------------------------------\n");
	/*-------------------------------------------------------------------------*/

	/* 2. Test data structures */
	printf("[TESTING DATA STRUCTURES] \n");

#ifdef LINKED_LIST
	printf("\nTEST OF LINKED LIST\n");
	linked_list::node* head = NULL;
	appendEnd(&head, 5);
	appendEnd(&head, 8);
	pushFront(&head, 4);
	insertAfter(head->next_node, 6);
	printLinkedList(head);

	deleteNode(&head, 4);
	deleteNode(head->next_node);
	printLinkedList(head);

	int Nth = 1;
	linked_list::node* NthNode = getNthNode(&head, Nth);
	printf("%dth node: %d\n", Nth, NthNode->data);

	deleteList(&head);
	printLinkedList(head);

	system("pause");
	printf("\n");
#endif // LINKED_LIST

#ifdef STACK
	printf("TEST OF STACK\n");
	int capacity = 10;
	stack::Stack* mystack = stack::createStack(capacity);
	push(mystack, 1);
	push(mystack, 3);
	push(mystack, 2);
	while (!isEmpty(mystack))
	{
		printf("Top item is: %d\n", peek(mystack));
		pop(mystack);
	}
	peek(mystack);
	pop(mystack);

	system("pause");
	printf("\n");

#endif

#ifdef QUEUE
	printf("TEST OF QUEUE\n");
	capacity = 10;
	queue::queue* myqueue = queue::createQueue(capacity);

	printQueue(myqueue);
	enqueue(myqueue, 0);
	enqueue(myqueue, 1);
	enqueue(myqueue, 2);
	enqueue(myqueue, 3);
	enqueue(myqueue, 4);
	printQueue(myqueue);
	dequeue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);

	system("pause");
	printf("\n");

#endif

#ifdef BINARY_TREE
	printf("TEST OF BINARY TREE\n");
	binary_tree::node* mynode = binary_tree::newNode(50);
	mynode->left = binary_tree::newNode(30);
	mynode->right = binary_tree::newNode(70);
	mynode->left->left = binary_tree::newNode(20);
	mynode->left->right = binary_tree::newNode(40);
	printNode(mynode);

	/* Test Binary Search Tree element insertion */
	printf("\n");
	bstInsert(mynode, 60);
	bstInsert(mynode, 80);
	printNode(mynode);

	/* Test Binary Search Tree element deletion */
	printf("\n");
	bstDelete(mynode, 20);
	//bstDelete(mynode, 2);
	//bstDelete(mynode, 3);
	printNode(mynode);

	system("pause");
	printf("\n");
#endif

#ifdef HEAP
	std::cout << "TEST OF BINARY HEAP \n";
	MinHeap myheap(5);
	myheap.insertKey(4);
	myheap.insertKey(0);
	myheap.insertKey(1);
	myheap.insertKey(6);
	myheap.insertKey(3);
	myheap.insertKey(5);  //This 6th element causes overflow
	std::cout << "GetMin: " << myheap.getMin() << std::endl;
	std::cout << "ExtractMin: " << myheap.extractMin() << std::endl;
	std::cout << "GetMin: " << myheap.getMin() << std::endl;
	myheap.decreaseKey(4, -1);
	std::cout << "GetMin: " << myheap.getMin() << std::endl;
	myheap.deleteKey(0);
	std::cout << "GetMin: " << myheap.getMin() << std::endl;
#endif

	return 1;

}


