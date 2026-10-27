#include <stdio.h>
int main(){
    int n, i, j, k, u = 0, v = 0, min, total = 0;
    int cost[20][20], visited[20] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    for(i = 0; i < n - 1; i++){
        min = 999;
        for(j = 0; j < n; j++){
            if(visited[j]){
                for(k = 0; k < n; k++){
                    if(!visited[k] && cost[j][k] < min){
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }
        printf("%d - %d = %d\n", u + 1, v + 1, min);
        total = total + min;
        visited[v] = 1;
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}