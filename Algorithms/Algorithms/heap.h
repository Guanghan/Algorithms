#include <iostream>

class MinHeap
{
	int *array;
	int capacity;  
	int heap_size;  //current # of elements in heap

public:
	/* Constructor */
	MinHeap(int capacity);

	/* Heapify a subtree with root at given index */
	void MinHeapify(int);

	/* Utility function: to swap */
	void swap(int *x, int *y);

	/* Get parent or child index based on the index of node */
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int left(int i)
	{
		return (2 * i + 1);
	}
	int right(int i)
	{
		return (2 * i + 2);
	}

	/* Extract root, the node with minimum value */
	int extractMin();

	/* Decrease the value of key at index 'i' to a new value, assuming new value is smaller */
	void decreaseKey(int i, int new_val);

	/* Delete a key stored at index i */
	void deleteKey(int i);

	/* Insert a new key */
	void insertKey(int key);

};