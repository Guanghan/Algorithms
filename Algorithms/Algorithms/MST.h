#include <stdio.h>
#include <limits.h>

namespace MST
{
	/* Number of Vertices in the graph*/
	#define V 5

	/* A ultility function to find the vertex with minimum key value,
	from the set of vertices not included yet in MST */
	int minKey(int key[], bool mstSet[]);

	/* A ultility function to print the constructed MST stored in parent[] */
	void printMST(int parent[], int n, int graph[V][V]);

	/* Function to construct and print MST for a graph represented by adjacency matrix */
	void primMST(int graph[V][V]);
}