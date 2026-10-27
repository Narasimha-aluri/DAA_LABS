#include<stdio.h>
int n,target;
int a[100],x[100];
void sumofsubsets(int i,int sum)
{
    int j;
    if(sum==target)
    {
        for(j=0;j<n;j++)
        {
            if(x[j])
                printf("%d ",a[j]);
        }
        printf("\n");
        return;
    }
    if(i==n||sum>target)
        return;
    x[i]=1;
    sumofsubsets(i+1,sum+a[i]);
    x[i]=0;
    sumofsubsets(i+1,sum);
}
int main()
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter target sum: ");
    scanf("%d",&target);
    printf("Subsets with sum %d are:\n",target);
    sumofsubsets(0,0);
    return 0;
}
