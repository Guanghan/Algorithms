/* This shows how a graph is represented using an adjacency list */

#include <stdio.h>
#include <stdlib.h>

namespace Graph
{
	/* The structure for the node in the Graph */
	struct AdjListNode
	{
		int value;
		AdjListNode* next;
	};

	/* The structure for the adjacency list in the Graph */
	struct AdjList
	{
		AdjListNode* head; //Pointer to the head of the list's node
	};

	/* The structure for the Graph itself */
	struct Graph
	{
		int vertexNum; //The vertex # of the Graph
		AdjList* list; //The adjacency list starting from this Vertex
	};

	/* Utility Function: Create a new adjacency list node*/
	AdjListNode* newAdjListNode(int value);

	/* Utility Function: Create a graph of N # of Vertexes */
	Graph* createGraph(int N);

	/* Add an edge to an undirected graph */
	void newEdge(Graph* mygraph, int src, int dest);

	/* Utility Function: Print the adjacency list representation of Graph */
	void printGraph(Graph* mygraph);
}
