#include <stdio.h>
void swap(int, int);
int main()
{
    int a, b;
    printf("Enter the two value to you want to swap : ");
    scanf("%d %d", &a, &b);
    printf("Before swapping the values in main a = %d, b = %d\n", a, b);
    swap(a, b);
}
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("After swapping values in function a = %d, b = %d\n", a, b);
}