#include <math.h>
#include <stdio.h>
#include<malloc.h>

void merge(float* Array, int low, int mid, int high){
	int i,j; //Two indices for the first and second half of the Array
	int k;   //index for the temporary array
	int len= high- low+ 1;   
	float* tempArray= (float*)malloc(sizeof(float)*high);   //later I will use malloc and release based on N 

	i= low-1;  k= low-1; 
	j= mid;
	
	while((i< mid)&&(j<high)){
		if(Array[i]<Array[j]){
			tempArray[k++]= Array[i++];
		}
		else{
			tempArray[k++]= Array[j++];
		}
	}
	
		while(i< mid){
			tempArray[k++]= Array[i++];
		}
	
		while(j< high){
			tempArray[k++]= Array[j++];
		}
	
	for (int n= low-1; n< high; n++){  //bug: it should start from n= low, not n= 0
		Array[n]= tempArray[n];
	}
	free(tempArray);

	return;
}


void merge_sort(float* Array, int low, int high){
	int mid;
	int n= high- low +1;

	if(low< high){  
		mid= (low+high)/2;
        merge_sort(Array, low, mid);
		merge_sort(Array, mid+1, high);
		merge(Array, low, mid, high);
	}
	else
		return;
}