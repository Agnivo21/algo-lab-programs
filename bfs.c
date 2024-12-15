#include<stdio.h>
#define MAX 100

void bfs(int graph[MAX][MAX],int start,int n,int visited[MAX])
{
    int queue[MAX],front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while(front< rear)
    {
        int curr = queue[front];front++;
        printf("%d ",curr);
        for(int i = 0;  i < n ;i++)
        {
            if(graph[curr][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] =1;
            }
        }
    }
}
int main(){
    int graph[MAX][MAX] = {
    {0, 1, 1, 0}, // Edges from node 0
    {1, 0, 0, 1}, // Edges from node 1
    {1, 0, 0, 1}, // Edges from node 2
    {0, 1, 1, 0}
};
    int visited[MAX] = {0};
    bfs(graph,0,4,visited);
}