#include <stdio.h>
#include <iostream>

#define INSERTION_SORT

int main( int argc, char** argv ){
	int Array[]= {23, 42, 54, 11, 32, 44, 76, 18, 23, 52, 31, 22, 10, 7, 21, 33, 23};
	int *Sorted= (int*)malloc(sizeof(Array));
	int key= Array[1];

	for (int i= 0; i< sizeof(Array)/sizeof(int); i++){
             printf("Array[%d]= %d\n", i, Array[i]);
	}

#ifdef INSERTION_SORT
	Sorted= insertion_sort(Array);
	for (int i= 0; i< sizeof(Array)/sizeof(int); i++){
             printf("Array[%d]= %d\n", i, Array[i]);  
	}
#endif
#ifdef MERGE_SORT
	Sorted= merge_sort(Array);
	for (int i= 0; i< sizeof(Array)/sizeof(int); i++){
             printf("Array[%d]= %d\n", i, Array[i]);  
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