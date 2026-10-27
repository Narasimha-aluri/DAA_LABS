#include <stdio.h>
#define MAX 10
#define INF 9999
int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INF;
void tsp(int city, int count, int totalCost)
{
    int i;
    if (count == n)
    {
        if (cost[city][0] != 0 && totalCost + cost[city][0] < minCost)
            minCost = totalCost + cost[city][0];
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0 && cost[city][i] != 0)
        {
            visited[i] = 1;
            tsp(i, count + 1, totalCost + cost[city][i]);
            visited[i] = 0;
        }
    }
}
int main()
{
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;
    tsp(0, 1, 0);
    printf("\nMinimum cost of travelling salesman tour = %d\n", minCost);
    return 0;
}