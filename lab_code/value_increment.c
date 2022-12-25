#include <stdio.h>
#include <conio.h>

void increment(int n);

int main()
{
    int n;

    printf("Enter the number you want to make this size of array : ");
    scanf("%d", &n);

    increment(n);

    return 0;
}

void increment(int n)
{

    int arr[n];
    int a;
    int arr1[n];
    int arr2[n];

    printf("Enter the value : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        arr1[i] = a;
    }

    printf("array befor increment : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr1[i]);
        printf("\n");
    }

    for (int j = 0; j < n; j++)
    {
        arr1[j] = arr1[j] + 5;
    }

    printf("array after increment : ");
    for (int k = 0; k < n; k++)
    {
        printf("%d", arr1[k]);
        printf("\n");
    }
}