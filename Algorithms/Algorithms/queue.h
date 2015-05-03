#include <stdio.h>
#include <stdlib.h>

namespace queue
{
	struct queue
	{
		int front, rear, occupancy;
		int *array;
		unsigned capacity;
	};

	/* Create a queue */
	queue* createQueue(unsigned capacity);

	/* Check empty */
	int isEmpty(queue* myqueue);

	/* Check Full */
	int isFull(queue* myqueue);

	/* Enqueue */
	void enqueue(queue* myqueue, int item);

	/* Dequeue, return the dequeued item */
	int dequeue(queue* myqueue);

	/* Get the front item */
	int getFront(queue* myqueue);

	/* Get the rear item */
	int getRear(queue* myqueue);

	/* Print the items in the queue */
	void printQueue(queue* myqueue);
}