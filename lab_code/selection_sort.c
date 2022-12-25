#include <stdio.h>
#include <stdlib.h>
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

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] <= a[min])
            {
                min = j;
            }
        }
        int temp;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    return 0;
}