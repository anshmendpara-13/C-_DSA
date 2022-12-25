#include <stdio.h>
#include <conio.h>

// #include <math.h>
int main()
{
    int n, num, max = 0, min = 0;

    printf("Enter the nubmer you want to compare : ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number : ");
        scanf("%d", &num);
        arr[i] = num;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else
        {
            max = max;
        }
    }

    printf("%d", max);

    

    return 0;
}