#include <stdio.h>
#include <conio.h>

// #include <math.h>
int main()
{
    int n, num;

    printf("Enter the nubmer you want to compare : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number : ");
        scanf("%d", &num);
        arr[i] = num;
    }

    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else
        {
            min = min;
        }
    }

    printf("%d", min);

    return 0;
}