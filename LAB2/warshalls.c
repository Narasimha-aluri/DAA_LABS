#include <stdio.h>
#define MAX 20
void warshall(int graph[MAX][MAX], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                graph[i][j] = graph[i][j] ||
                               (graph[i][k] && graph[k][j]);
            }
        }
    }
    printf("\nTransitive Closure of the Graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void topologicalSort(int graph[MAX][MAX], int n)
{
    int indegree[MAX] = {0};
    int order[MAX];
    int i, j, k = 0;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[j][i] == 1)
                indegree[i]++;
        }
    }
    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                order[k++] = i;
                indegree[i] = -1;
                count++;
                found = 1;
                for (j = 0; j < n; j++)
                {
                    if (graph[i][j] == 1)
                        indegree[j]--;
                }
            }
        }
        if (found == 0)
        {
            printf("\nTopological ordering is not possible.");
            printf("\nThe graph contains a cycle.\n");
            return;
        }
    }
    printf("\nTopological Ordering:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");
}
int main()
{
    int graph[MAX][MAX];
    int closure[MAX][MAX];
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            closure[i][j] = graph[i][j];
        }
    }
    topologicalSort(graph, n);
    warshall(closure, n);
    return 0;
}
