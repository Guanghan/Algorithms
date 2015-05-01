#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

namespace stack
{
	struct Stack
	{
		int top;
		unsigned capacity;
		int* array;
	};

	/* Create a stack of size capacity */
	Stack* createStack(int capacity);

	/* Stack is full when the top obj is at the top of the container */
	int isFull(Stack* stack);

	/* Stack is empty when the top obj is -1, lower than the bottom(which is 0) of the container */
	int isEmpty(Stack* stack);

	/* Push an item into the stack */
	void push(Stack* mystack, int item);

	/* Pop an item out of the stack */
	void pop(Stack* mystack);

	/* Get the top item in the stack */
	int peek(Stack* mystack);

	/* Show me the stack */
	void printStack(Stack* mystack);

}
