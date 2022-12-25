#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int B[], int mid, int low, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int B[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, B, low, mid);
        mergeSort(A, B, mid + 1, high);
        merge(A, B, mid, low, high);
    }
}

int main()
{
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int A[n];
    int B[n];
    for (int i = 0; i < n; i++)
    {
        int c;
        printf("Enter element : ");
        scanf("%d", &c);
        A[i] = c;
    }

    printf("array before sort : ");
    printArray(A, n);
    mergeSort(A, B, 0, n - 1);
    printf("array after sort : ");
    printArray(A, n);
    return 0;
}
