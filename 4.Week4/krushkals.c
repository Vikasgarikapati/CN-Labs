#include <stdio.h>
#define MAX 30

struct edge
{
	int u, v;	// Vertices connected by the edge
	int weight; // Weight of the connected edge
};

struct edgeList
{
	struct edge data[MAX];
	int n;
};

int G[MAX][MAX], n;

struct edgeList edgeSet;
struct edgeList span;

int find(int belongs[], int vno)
{
	return (belongs[vno]);
}

void applyUnion(int belongs[], int c1, int c2)

{
	int i;

	for (i = 0; i < n; i++)
	{
		if (belongs[i] == c2)
			belongs[i] = c1;
	}
}

void kruskal()
{
	int belongs[MAX], i = 0, j = 0, c1, c2;
	edgeSet.n = 0;

	// To generate the list of edges from the Adjacency Matrix
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
		{
			if (G[i][j] != 0)
			{
				edgeSet.data[edgeSet.n].u = i;
				edgeSet.data[edgeSet.n].v = j;
				edgeSet.data[edgeSet.n].weight = G[i][j];
				edgeSet.n++;
			}
		}

	// Sort the list of edges
	struct edge temp;

	for (i = 1; i < edgeSet.n; i++)
	{
		for (j = 0; j < edgeSet.n - 1; j++)
		{
			if (edgeSet.data[j].weight > edgeSet.data[j + 1].weight)
			{
				temp = edgeSet.data[j];
				edgeSet.data[j] = edgeSet.data[j + 1];
				edgeSet.data[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
		belongs[i] = i;

	span.n = 0;

	for (i = 0; i < edgeSet.n; i++)
	{
		c1 = find(belongs, edgeSet.data[i].u);
		c2 = find(belongs, edgeSet.data[i].v);

		if (c1 != c2)
		{
			span.data[span.n] = edgeSet.data[i];
			span.n = span.n + 1;
			applyUnion(belongs, c1, c2);
		}
	}
}

void print()
{
	int i, cost = 0;

	printf("Edges of Kruskal's Min. Spanning Tree : \n");

	for (i = 0; i < span.n; i++)
	{
		printf("\n%d - %d : %d", span.data[i].u, span.data[i].v, span.data[i].weight);
		cost = cost + span.data[i].weight;
	}

	printf("\n\nKruskal's Min. Spanning tree cost: %d", cost);
}

int main()
{
	printf("@@@@@@@@@@@@ KRUSKAL'S MINIMUM SPANNING TREE@@@@@@@@@@@@\n\n");

	printf("Enter the total no. of vertices in the graph : ");
	scanf("%d", &n);

	printf("\n");

	// Let the vertices of the Graph be from 0 to n-1

	/*Adjacency matrix for the Graph: a) For connected components -> Enter their weights
	b) For non-connected components -> Enter zero */

	printf("ENTER THE WEIGHTS ('0' for non-connected edges) :\n\n");

	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		printf("Edges generated from vertex %d : ", i);
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("Weight of edge %d -- %d : ", i, j);
			scanf("%d", &G[i][j]);
		}

		printf("\n");
	}

	kruskal();
	print();

	return 0;
}
