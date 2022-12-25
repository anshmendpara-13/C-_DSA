#include <stdio.h>
#include <stdlib.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1);
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int c;
        printf("Enter element : ");
        scanf("%d", &c);
        a[i] = c;
    }
    printf("array before sort : ");
    printarray(a, n);
    quicksort(a, 0, n - 1);
    printf("array after sort : ");
    printarray(a, n);
}