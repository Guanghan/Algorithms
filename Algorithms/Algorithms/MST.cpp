#include "MST.h"

namespace MST
{
	/* Number of Vertices in the graph*/
	#define V 5

	/* A ultility function to find the vertex with minimum key value,
	   from the set of vertices not included yet in MST */
	int minKey(int key[], bool mstSet[])
	{
		// Initialize min value
		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
		{
			if (mstSet[v] == false && key[v] < min)
			{
				min = key[v];
				min_index = v;
			}
		}

		return min_index;
	}

	/* A ultility function to print the constructed MST stored in parent[] */
	void printMST(int parent[], int n, int graph[V][V])
	{
		printf("Edge Weight\n");
		for (int v = 1; v < V; v++)
		{
			printf("(%d - %d): %d\n",  parent[v], parent[v] , graph[v][parent[v]]);
		}
	}

	/* Function to construct and print MST for a graph represented by adjacency matrix */
	void primMST(int graph[V][V])
	{
		int parent[V]; // Array to store constructed MST
		int key[V]; // Key values used to pick minimum weight edge in cut
		bool mstSet[V]; //To represent set of vertices not yet included in MST

		/* Initialize all keys as INFINITE */
		for (int i = 0; i < V; i++)
		{
			key[i] = INT_MAX;
			mstSet[i] = false;
		}

		/* Always include fitst vertex in the MST */
		key[0] = 0;     //Make its key 0 so it is picked as first vertex
		parent[0] = -1; //First node is always root of MST

		/* The MST has V vertices */
		for (int count = 0; count < V - 1; count++)
		{
			//1. find the vertex(not in MST yet) with minimum key value, update the minminum value and index
			int u = minKey(key, mstSet);

			//2. Add this vertex into MST
			mstSet[u] = true;

			//3. Update parent index and key value of each vertex
			for (int v = 0; v < V; v++)
			{
				if (graph[u][v]      // u and v must be adjacent/connected in graph 
					&& mstSet[v] == false   // for vertices not yet in MST
					&& graph[u][v] < key[v]) // update the key only if necessary
				{
					parent[v] = u;
					key[v] = graph[u][v];
				}
			}
		}

		// Print the constructed MST
		printMST(parent, V, graph);
	}
}