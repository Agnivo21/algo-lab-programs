#include<stdio.h>
#define MAX 100

void dfs(int n,int arr[MAX][MAX], int start,int visited[MAX])
{
    if(visited[start] == 0){
    printf("%d ",start);
    visited[start] = 1;
    for(int i = 0 ; i < n ;i++)
    {
        if(arr[start][i] ==1 && visited[i] == 0 )
        dfs(n,arr,i,visited);
    }
    }
}
int main(){
    int graph[MAX][MAX] = {
    {0, 1, 0, 0, 0}, // Edges from node 0
    {1, 0, 1, 0, 0}, // Edges from node 1
    {0, 1, 0, 1, 1}, // Edges from node 2
    {0, 0, 1, 0, 0}, // Edges from node 3
    {0, 0, 1, 0, 0}  // Edges from node 4
};
    int visited[MAX] = {0};
    dfs(5,graph,1,visited);
}