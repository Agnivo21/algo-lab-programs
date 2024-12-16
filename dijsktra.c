#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // Number of vertices

int selectMinVertex(int value[], bool processed[])
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i)
    {
        if (!processed[i] && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void dijkstra(int graph[V][V])
{
    int parent[V];          // Stores Shortest Path Structure
    int value[V];           // Keeps shortest path values to each vertex from source
    bool processed[V];      // TRUE -> Vertex is processed

    for (int i = 0; i < V; ++i)
    {
        value[i] = INT_MAX; // Initialize all distances as infinite
        processed[i] = false;
    }

    parent[0] = -1; // Start node has no parent
    value[0] = 0;   // Start node has value=0 to get picked first

    for (int i = 0; i < V - 1; ++i)
    {
        int U = selectMinVertex(value, processed);
        processed[U] = true; // Include new Vertex in shortest Path Graph

        for (int j = 0; j < V; ++j)
        {
            // 3 conditions to relax:
            // 1. Edge is present from U to j
            // 2. Vertex j is not included in shortest path graph
            // 3. New path is shorter than current path
            if (graph[U][j] != 0 && !processed[j] && value[U] != INT_MAX &&
                value[U] + graph[U][j] < value[j])
            {
                value[j] = value[U] + graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Print Shortest Path Graph
    for (int i = 1; i < V; ++i)
    {
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main()
{
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                       {1, 0, 4, 2, 7, 0},
                       {4, 4, 0, 3, 5, 0},
                       {0, 2, 3, 0, 4, 6},
                       {0, 7, 5, 4, 0, 7},
                       {0, 0, 0, 6, 7, 0}};

    dijkstra(graph);
    return 0;
}
