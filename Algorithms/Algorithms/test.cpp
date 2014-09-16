#include <stdio.h>
#include <iostream>
#include "test.h"

#define INSERTION_SORT

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





/*
#include<stdio.h>


void Insert(int *a,int n)//把数组a的第n个数插入前n-1个数中，注意前n-1个数已经是排好序的了
{
    int i=n-1;
    int key=a[n];
    while((i>=0)&&(key<a[i]))
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=key;
    return;
}

void InsertionSort(int *a,int n)//递归插入，跟求阶乘的思想一样，前n-1个排好序的数组，是建立在前n-2个排好序的数组的基础上插出来的
{
    if(n>0)
    {
        InsertionSort(a,n-1);
        Insert(a,n);
    }
    else 
        return;
}


void main()
{
    int i,n,a[30];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    InsertionSort(a,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return;
}*/