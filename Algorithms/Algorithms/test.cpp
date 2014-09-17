#include <stdio.h>
#include <iostream>
#include "test.h"

//#define INSERTION_SORT
#define  MERGE_SORT

int main( int argc, char** argv ){
	float Array[]= {23, 42, 54, 11, 32, 44, 76, 18, 23, 52, 31, 22, 10, 7, 21, 33, 23};
	float *Sorted= (float*)malloc(sizeof(Array));
	float key= Array[1];

	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
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
	int N= sizeof(Array)/sizeof(float);

	merge_sort(A, 1, N);   printf("Merge finish\n");
	for (int i= 0; i< sizeof(Array)/sizeof(float); i++){
       printf("Array[%d]= %f\n", i, Array[i]);  
	}
#endif
#ifdef BINARY_SEARCH
	Sorted= insertion_sort(Array);
	for (int i= 0; i< sizeof(Array)/sizeof(int); i++){
             printf("Array[%d]= %d\n", i, Array[i]);  
	}
	int index= binary_search(Sorted, key);
    printf("Array[1]= Sorted[%d]= %d\n",key, Sorted[key]);  
#endif
	system("pause");
}

