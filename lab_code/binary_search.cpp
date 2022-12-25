#include <bits/stdc++.h>
#include <iostream>

void binary_search(int a[], int n, int key);

int main()
{
    int n;
    printf("Enter size of array :- ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        printf("Enter the value : ");
        scanf("%d", &k);
        a[i] = k;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            else
            {
                a[j] = a[j];
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    int key;
    printf("Enter the key : ");
    scanf("%d", &key);

    binary_search(a, n, key);
}

void binary_search(int a[], int n, int key)
{

    int first = 0;
    int last = n;
    for (int i = 0; i < n; i++)
    {
        int mid = (first + last) / 2;

        if (key == a[mid])
        {
            printf("your value is found in %d position ", mid + 1);
            break;
        }
        else
        {
            if (a[mid] <= key)
            {
                first = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
        }
    }
}
