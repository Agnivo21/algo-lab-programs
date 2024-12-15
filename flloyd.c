#include<stdio.h>
#define v 4
#define INF 9999
void printfloyd(int graph[v][v])
{
    for(int i = 0 ; i < v ; i++)
    {
        for(int j =0 ; j < v ;j++)
        {
            if(graph[i][j] == INF)
            printf("%s ","INF");
            else
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void floyd(int graph[v][v])
{
    int i,j,k;
    for(int k = 0 ; k < v ; k++)
    {
        for(int i = 0 ; i < v ;i++)
        {
            for(int j = 0; j < v ;j++)
            {
                if(graph[i][k] + graph[k][j]<graph[i][j])
                graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    printfloyd(graph);
}
int main(){
    int graph[v][v] = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}};
    floyd(graph);
    return 0;
}