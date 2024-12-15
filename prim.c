#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define v 5
int setminvertex(int value[],bool setmst[])
{
    int min = INT_MAX;
    int vertex = 0;
    for(int i = 0 ; i < v ; i++)
    {
        if(setmst[i] != true && value[i] < min)
        {
            min = value[i];
            vertex = i; 
        }
    }
    return vertex;
}
void fintmst(int graph[v][v])
{
    int value[v];
    bool setmst[v];
    int parent [v];
    for(int i = 0; i < v;i++)
    {
        value[i] = INT_MAX;
        setmst[i] = false;
    }
    value[0] = 0;
    parent[0] =-1;
    for(int i = 0 ; i < v-1; i++)
    {
        int u = setminvertex(value,setmst);
        setmst[u] = true;
        for(int j = 0 ; j < v ; j++)
        {
            if(graph[u][j] != 0 && setmst[j] != true && graph[u][j] < value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    // Print MST
    for (int i = 1; i < v; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}
int main()
{
    int graph[v][v] = 
    {{0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}};
    fintmst(graph);
    return 0;
}