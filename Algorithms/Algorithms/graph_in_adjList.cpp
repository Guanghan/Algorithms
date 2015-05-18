/* This shows how a graph is represented using an adjacency list */

#include "graph_in_adjList.h"

namespace Graph
{
	/* Utility Function: Create a new adjacency list node*/
	AdjListNode* newAdjListNode(int value)
	{
		AdjListNode* newnode = (AdjListNode*)malloc(sizeof(AdjListNode));
		newnode->value = value;
		newnode->next = NULL;
		
		return newnode;
	}

	/* Utility Function: Create a graph of N # of Vertexes */
	Graph* createGraph(int N)
	{
		Graph* mygraph = (Graph*)malloc(sizeof(Graph));
		mygraph->vertexNum = N;

		//Create an array of adjacency lists, each vertex a list
		mygraph->list = (AdjList*)malloc(N*sizeof(AdjList));

		//Initialize each adjacency list as empty by making their pointers to the head NULL
		for (int i = 0; i < N; i++)
		{
			mygraph->list[i].head = NULL;
		}

		return mygraph;
	}

	/* Add an edge to an undirected graph, with the values of the two vertexes being [src_val] and [dest_val] */
	void newEdge(Graph* mygraph, int src, int dest)
	{
		// Add an edge from src to dest. A new node is added to the adjacency list of src.
		AdjListNode* newNode = newAdjListNode(dest);  //new node has value dest
		newNode->next = mygraph->list[src].head; //the node's next node is src_th list's head 
		mygraph->list[src].head = newNode;  //the graph's src_th list's head node is this node

		// Since graph is undirected, add an edge from dest to src also
		newNode = newAdjListNode(src);
		newNode->next = mygraph->list[dest].head;
		mygraph->list[dest].head = newNode;
	}

	/* Utility Function: Print the adjacency list representation of Graph */
	void printGraph(Graph* mygraph)
	{
		for (int v = 0; v < mygraph->vertexNum; v++)
		{
			AdjListNode* pCrawl = mygraph->list[v].head;
			printf("\n Adjacency list of vertex %d\n head ", v);
			while (pCrawl)
			{
				printf("-> %d", pCrawl->value);
				pCrawl = pCrawl->next;
			}
			printf("\n");
		}
	}
}