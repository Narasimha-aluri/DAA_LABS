#include <stdio.h>

int main()
{
    int n, capacity;
    int weight[20], profit[20];
    int dp[20][20];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter bag capacity: ");
    scanf("%d", &capacity);
    printf("Enter weights of items:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
    }
    printf("Enter profits of items:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &profit[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weight[i] <= w)
            {
                int include = profit[i] + dp[i - 1][w - weight[i]];
                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}