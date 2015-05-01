#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

namespace stack
{
	/* Create a stack of size capacity */
	Stack* createStack(int capacity)
	{
		Stack* mystack = (Stack *)malloc(sizeof(Stack));
		mystack->capacity = capacity;
		mystack->top = -1; //Empty
		mystack->array = (int *)malloc(capacity*sizeof(int));

		return mystack;
	}

	/* Stack is full when the top obj is at the top of the container */
	int isFull(Stack* mystack)
	{
		return mystack->top == mystack->capacity - 1;
	}

	/* Stack is empty when the top obj is -1, lower than the bottom(which is 0) of the container */
	int isEmpty(Stack* mystack)
	{
		return mystack->top == -1;
	}

	/* Push an item into the stack */
	void push(Stack* mystack, int item)
	{
		if (isFull(mystack))
		{
			printf("Error: in function stack::push(Stack* mystack, int item), the stack is already full!\n");
			return;
		}
		else
		{
			mystack->top++;
			mystack->array[mystack->top] = item;
			printf("Item %d pushed to stack\n", item);
		}
	}

	/* Pop an item out of the stack */
	void pop(Stack* mystack)
	{
		if (isEmpty(mystack))
		{
			printf("Warning: in function stack:pop(Stack* mystack), the stack is empty and there is nothing to pop.\n");
			return;
		}
		mystack->top--;
	}

	/* Get the top item in the stack */
	int peek(Stack* mystack)
	{
		if (isEmpty(mystack))
		{
			printf("Warning: in function stack:peek(Stack* mystack), the stack is empty and there is nothing to peek.\n");
			return INT_MIN;
		}
		return mystack->array[mystack->top];
	}

	/* Show me the stack */
	void printStack(Stack* mystack)
	{
		if (isEmpty(mystack))
		{
			printf("Stack Empty\n");
			return;
		}
		for (int i = 0; i < mystack->top + 1; i++)
		{
			printf("%d ", mystack->array[i]);
		}
	}
}