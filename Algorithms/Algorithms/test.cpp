#include <stdio.h>
#include <iostream>

#define INSERTION_SORT

int main( int argc, char** argv ){
	int Array[]= {23, 42, 54, 11, 32, 44, 76, 18, 23, 52, 31, 22, 10, 7, 21, 33, 23};
	int *Sorted= (int*)malloc(sizeof(Array));

	for (int i= 0; i< sizeof(Array)/sizeof(int); i++){
             printf("Array[%d]= %d\n", i, Array[i]);
	}

#ifdef INSERTION_SORT
	
    

#endif
	
	system("pause");
}