/* This shows how a graph is represented using an adjacency list */

#include "BFT.h"

class Graph
{
	/* The structure for the node in the Graph */
	typedef struct AdjListNode
	{
		int value;
		AdjListNode* next;
	};

	/* The structure for the adjacency list in the Graph */
	struct AdjList
	{
		AdjListNode* head; //Pointer to the head of the list's node
	};

public:
	/* The structure for the Graph itself */
	int vertexNum; //The vertex # of the Graph
	AdjList* list; //The adjacency list starting from this Vertex

	/* Constrctor: Create a graph of N # of Vertexes */
	Graph::Graph(int N)
	{
		this->vertexNum = N;

		//Create an array of adjacency lists, each vertex a list
		this->list = (AdjList*)malloc(N*sizeof(AdjList));

		//Initialize each adjacency list as empty by making their pointers to the head NULL
		for (int i = 0; i < N; i++)
		{
			this->list[i].head = NULL;
		}
	}

	/* Utility Function: Create a new adjacency list node*/
	AdjListNode* Graph::newAdjListNode(int value)
	{
		AdjListNode* newnode = (AdjListNode*)malloc(sizeof(AdjListNode));
		newnode->value = value;
		newnode->next = NULL;

		return newnode;
	}

	/* Add an edge to an undirected graph, with the values of the two vertexes being [src_val] and [dest_val] */
	void newEdge(int src, int dest)
	{
		// Add an edge from src to dest. A new node is added to the adjacency list of src.
		AdjListNode* newNode = newAdjListNode(dest);  //new node has value dest
		newNode->next = this->list[src].head; //the node's next node is src_th list's head 
		this->list[src].head = newNode;  //the graph's src_th list's head node is this node

		// Since graph is undirected, add an edge from dest to src also
		newNode = newAdjListNode(src);
		newNode->next = this->list[dest].head;
		this->list[dest].head = newNode;
	}

	/* Utility Function: Print the adjacency list representation of Graph */
	void printGraph()
	{
		for (int v = 0; v < this->vertexNum; v++)
		{
			AdjListNode* pCrawl = this->list[v].head;
			printf("\n Adjacency list of vertex %d\n head ", v);
			while (pCrawl)
			{
				printf("-> %d", pCrawl->value);
				pCrawl = pCrawl->next;
			}
			printf("\n");
		}
	}

	/* Breadth First Traversal(BFT) or called Search for the graph */
	void BFS(int s)
	{
		// Mark all the vertives as not visited
		bool *visited = new bool[vertexNum];
		for (int i = 0; i < vertexNum; i++)
			visited[i] = false;

		// Create a queue for BFS
		std::list<int> queue;

		// Mark the current node as visited and enqueue it 
		visited[s] = true;
		queue.push_back(s);

		while (!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			s = queue.front();
			std::cout << s << " ";
			queue.pop_front();

			// Get all adjacent vertices of the dequeued vertex s
			// If an adjacent has not been visited, make it visited and enqueue it
			AdjListNode* pCrawl = this->list[s].head;
			int i = 0;
			while (pCrawl != NULL)
			{
				if (!visited[i])
				{
					visited[i] = true;
					queue.push_back(i);
				}
				pCrawl = pCrawl->next;
				i++;
			}
		}
	}
};
