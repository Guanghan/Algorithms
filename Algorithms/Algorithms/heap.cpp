#include "heap.h"

using namespace std;

/* Constructor */
MinHeap::MinHeap(int capacity)
{
	heap_size = 0;
	array = new int[capacity]; //rather than using malloc
	this->capacity = capacity;
}

/* Utility function: */

/* Heapify a subtree with root at given index */
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && array[l] < array[i])
		smallest = l;
	if (r < heap_size && array[r] < array[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&array[i], &array[smallest]);
		MinHeapify(smallest);
	}
}

/* Extract root, the node with minimum value */
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return array[0];
	}

	//store the minumum value, and remove it from heap
	int root = array[0];
	array[0] = array[heap_size - 1]; //? Any element will do
	heap_size--;
	MinHeapify(0);

	return root;

}

/* Decrease the value of key at index 'i' to a new value, assuming new value is smaller */
void MinHeap::decreaseKey(int i, int new_val)
{
	array[i] = new_val;
	while (i != 0 && array[parent(i)] > array[i])
	{
		swap(&array[i], &array[parent(i)]);
		i = parent(i);
	}
}

/* Delete a key stored at index i */
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

/* Insert a new key */
void MinHeap::insertKey(int key)
{
	if (heap_size == capacity)
	{
		cout << "Error in MinHeap::insertKey(int key), Overflow!\n";
		return;
	}

	//Insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	array[i] = key;

	//Fix the min heap property if violated
	while (i != 0 && array[parent(i)] > array[i])
	{
		swap(&array[i], &array[parent(i)]);
		i = parent(i);
	}

}