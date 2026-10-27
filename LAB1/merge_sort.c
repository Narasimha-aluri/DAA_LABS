#include <stdio.h>
void merge(int a[], int temp[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high){
        temp[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int a[], int temp[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(a, temp, low, mid);
        mergeSort(a, temp, mid + 1, high);
        merge(a, temp, low, mid, high);
    }
}
int main()
{
    int a[100], temp[100];
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, temp, 0, n - 1);
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}