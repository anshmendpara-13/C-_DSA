#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int *a, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void bubblesortadaptive(int *a, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("working on pass number %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
            if (issorted)
            {
                return;
            }
        }
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = 11;
    printarray(a, n);
    bubblesort(a, n);
    printarray(a, n);
    return 0;
}