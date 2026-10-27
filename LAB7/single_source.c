#include <stdio.h>
#define MAX 10
#define INF 9999
int graph[MAX][MAX];
int visited[MAX];
int n;
void dijkstra(int source)
{
    int dist[MAX];
    int used[MAX];
    int i, j, min, u;
    for (i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
        used[i] = 0;
    }
    dist[source] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++)
        {
            if (used[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        used[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (used[j] == 0 && graph[u][j] != INF && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }
    printf("\nShortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d = INF\n", i);
        else
            printf("Vertex %d = %d\n", i, dist[i]);
    }
}
void dfs(int vertex)
{
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] != INF && graph[vertex][i] != 0 && visited[i] == 0)
            dfs(i);
    }
}
void connectedComponents()
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nConnected Components:\n");
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            printf("Component %d: ", count);
            dfs(i);
            printf("\n");
        }
    }
    printf("Total Connected Components = %d\n", count);
}
int main()
{
    int i, j, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    connectedComponents();
    return 0;
}
