#include "queue.h"


namespace queue
{
	/* Create a queue */
	queue* createQueue(unsigned capacity)
	{
		queue* myqueue = (queue*)malloc(sizeof(queue));
		myqueue->array = (int*)malloc(capacity*sizeof(int));
		myqueue->capacity = capacity;
		myqueue->front = -1;
		myqueue->rear = -1;
		myqueue->occupancy = 0;

		return myqueue;
	}

	/* Check empty */
	int isEmpty(queue* myqueue)
	{
		if (myqueue->occupancy == 0)
			return 1;
		else return 0;
	}

	/* Check Full */
	int isFull(queue* myqueue)
	{
		if (myqueue->occupancy == myqueue->capacity)
			return 1;
		else
			return 0;
	}

	/* Enqueue */
	void enqueue(queue* myqueue, int item)
	{
		if (isEmpty(myqueue)) //initialize rear
			myqueue->front++;

		if (!isFull(myqueue)) //make sure there is room to enqueue
		{
			myqueue->rear = (myqueue->rear + 1) % myqueue->capacity;
			myqueue->occupancy++;

			myqueue->array[myqueue->rear] = item;
		}
		else
		{
			printf("Error in queue::enqueue(queue* myqueue, int item), queue is already full\n");
			return;
		}
	}

	/* Dequeue, return the dequeued item */
	int dequeue(queue* myqueue)
	{
		int temp = myqueue->array[myqueue->front];

		if (!isEmpty(myqueue)) //make sure there is something to dequeue
		{
			myqueue->front = (myqueue->front + 1) % myqueue->capacity;
			myqueue->occupancy--;

			return temp;
		}
		else
		{
			printf("Error in queue:dequeue(queue* myqueque), no item to dequeue\n");
			return INT_MIN;
		}

	}

	/* Get the front item */
	int getFront(queue* myqueue)
	{
		if (isEmpty(myqueue)) return INT_MIN;
		return myqueue->array[myqueue->front];
	}

	/* Get the rear item */
	int getRear(queue* myqueue)
	{
		if (isEmpty(myqueue)) return INT_MIN;
		return myqueue->array[myqueue->rear];
	}

	/* Print the items in the queue */
	void printQueue(queue* myqueue)
	{
		if (isEmpty(myqueue))
		{
			printf("Queue is empty");
		}
		else if (myqueue->rear > myqueue->front)
		{
			for (int i = myqueue->front; i <= myqueue->rear; i++)
				printf("%d ", myqueue->array[i]);
		}
		else
		{
			for (int i = myqueue->front; i < myqueue->capacity; i++)
				printf("%d ", myqueue->array[i]);
			for (int i = 0; i <= myqueue->rear; i++)
				printf("%d ", myqueue->array[i]);
		}

		printf("\n");
	}
}