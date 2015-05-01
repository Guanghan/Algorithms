#include <stdio.h>
#include <iostream>
#include "test.h"

//#define MERGE_SORT
//#define INSERTION_SORT
#define  QUICK_SORT
#define  LINKED_LIST

int main( int argc, char** argv )
{
	/* 1. Test algorithms */

	float Array[] = { 23, 42, 54, 11, 32, 44, 76, 18, 23, 52, 31, 22, 10, 7, 21, 33, 23 };
	float *Sorted = (float*)malloc(sizeof(Array));
	float key = Array[1];

	for (int i = 0; i< sizeof(Array) / sizeof(float); i++){
		printf("Array[%d]= %f\n", i, Array[i]);
	} printf("\n");

#ifdef INSERTION_SORT
	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float);

	insertion_sort(A, N);
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
             printf("Array[%d]= %f\n", i, Array[i]);  
	}
#endif
#ifdef MERGE_SORT
	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float); printf("N= %d\n", N);

	merge_sort(A, 1, 17);   printf("Merge finish\n");
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
       printf("Array[%d]= %f\n", i, Array[i]); 
	}
#endif
#ifdef QUICK_SORT
	float* A= &Array[0];
	int N= sizeof(Array)/sizeof(float);

	quick_sort(Array, 1, 17);
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
       printf("Array[%d]= %f\n", i, Array[i]); 
	}
#endif
	system("pause");
	printf("\n");

	/*-------------------------------------------------------------------------*/

	/* 2. Test data structures */

#ifdef LINKED_LIST
	node* head = NULL;
	appendEnd(&head, 5);
	appendEnd(&head, 8);
	pushFront(&head, 4);
	insertAfter(head->next_node, 6);
	printLinkedList(head);

	deleteNode(&head, 4);
	deleteNode(head->next_node);
	printLinkedList(head);

	int Nth = 1;
	node* NthNode = getNthNode(&head, Nth);
	printf("%dth node: %d\n", Nth, NthNode->data);

	deleteList(&head);
	printLinkedList(head);
#endif // LINKED_LIST


	return 1;

}


