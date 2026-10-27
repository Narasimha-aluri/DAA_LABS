#include<stdio.h>
int a[9][9];
int issafe(int r,int c,int n)
{
    int i,j;
    for(i=0;i<9;i++)
        if(a[r][i]==n||a[i][c]==n)
            return 0;
    for(i=(r/3)*3;i<(r/3)*3+3;i++)
        for(j=(c/3)*3;j<(c/3)*3+3;j++)
            if(a[i][j]==n)
                return 0;
    return 1;
}
int solve()
{
    int i,j,n;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(a[i][j]==0)
            {
                for(n=1;n<=9;n++)
                {
                    if(issafe(i,j,n))
                    {
                        a[i][j]=n;
                        if(solve())
                            return 1;
                        a[i][j]=0;
                    }
                }
                return 0;
            }
    return 1;
}
int main()
{
    int i,j;
    printf("Enter the Sudoku puzzle:\n");
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            scanf("%d",&a[i][j]);
    if(solve())
    {
        printf("Solved Sudoku:\n");
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    else
        printf("No solution exists\n");
    return 0;
}
