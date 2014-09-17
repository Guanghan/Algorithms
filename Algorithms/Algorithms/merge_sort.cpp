#include <math.h>
#include <stdio.h>
#include<malloc.h>

void merge(float* Array, int low, int mid, int high){
	printf("Hey, I am merging!\n");
	int i,j; //Two indices for the first and second half of the Array
	int k;   //index for the temporary array
	int len= high- low+ 1;
	float* tempArray= (float*)malloc(sizeof(float)*len);   //later I will use malloc and release based on N 

	i= low;
	j= mid+ 1;
	k= low-1; 
	while((i<=mid)&&(j<=high)){
		k++;
		if(Array[i]<Array[j]){
			tempArray[k]= Array[i];
			i++;
		}
		else{
			tempArray[k]= Array[j];
			j++;
		}
	    printf("Hey, I am in the first while loop!\n");	
	}
	//if(j==high){
		while(i<=mid){
			k++;
			tempArray[k]= Array[i];
			i++;
			  printf("Hey, I am in the 2nd while loop!\n");
		}
	//}
	//if(i==mid){
		while(j<=high){
			k++;
			tempArray[k]= Array[j];
			j++;
			printf("Hey, I am in the 3rd while loop!\n");printf("%d %d\n", k, j);
		}
	//}
	for (int n=0; n< len; n++){
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
	//mid= floor(float(low+high)/2);
    printf("Again\n");
	//if(n<= 2) return;
    //if(n== 3) merge(Array, low, mid, high);
	if(low< high){
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