#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a, b;

    printf("Enter the two value you want to swap : ");
    scanf("%d%d", &a, &b);

    printf("Before swapping : a = %d and b = %d", a, b);

    swap(&a, &b);

    printf("\nAfter swapping : a = %d and b = %d", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}