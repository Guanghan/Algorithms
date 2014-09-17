#include <math.h>
#include <stdio.h>
#include<malloc.h>

void merge(float* Array, int low, int mid, int high){
	printf("Hey, I am merging!\n");
	int i,j; //Two indices for the first and second half of the Array
	int k;   //index for the temporary array
	int len= high- low+ 1;
	float* tempArray= (float*)malloc(sizeof(float)*len);   //later I will use malloc and release based on N 

	i= low-1;  k= low; 
	//j= mid+1;
	j= mid;
	
	while((i<mid)&&(j<high)){
		if(Array[i]<Array[j]){
			tempArray[k++]= Array[i++];
		}
		else{
			tempArray[k++]= Array[j++];
		}
	    printf("Hey, I am in the first while loop!\n");	
	}
	
		while(i< mid){
			tempArray[k++]= Array[i++];
			  printf("Hey, I am in the 2nd while loop!\n");
		}
	
		while(j<high){
			tempArray[k++]= Array[j++];
			printf("Hey, I am in the 3rd while loop!\n");printf("%d %d\n", k, j);
		}
	
	for (int n= low; n< high; n++){  //bug2: it should start from n= low, not n= 0
		Array[n]= tempArray[n];
		printf("Array[%d]= %f\n", n, Array[n]);
	}
	printf("Hey, I copied myself!\n");
	//free(tempArray);

	return;
}


void merge_sort(float* Array, int low, int high){
	int mid;
	int n= high- low +1;
    printf("Again\n");

	if(low+1< high){   //bug1: not low<high
		mid= (low+high)/2;
		printf("low= %d\n mid= %d\n high= %d\n", low, mid, high);
        merge_sort(Array, low, mid);
		printf("Second Half\n");
		merge_sort(Array, mid+1, high);
		merge(Array, low, mid, high);
	}
	else
		return;
}