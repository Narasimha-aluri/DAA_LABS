#include <stdio.h>
int parent[20];
int find(int i){
    while(parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main(){
    int n, i, j, edges = 0;
    int cost[20][20];
    int min, u = 0, v = 0, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++){
        parent[i] = i;
        for(j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    while(edges < n - 1){
        min = 999;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if(find(u) != find(v)){
            printf("%d - %d = %d\n", u + 1, v + 1, min);
            total = total + min;
            edges++;
            unionSet(u, v);
        }
        cost[u][v] = 999;
        cost[v][u] = 999;
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}