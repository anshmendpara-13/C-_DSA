#include <stdio.h>
#include <conio.h>

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping A is : %d and B is : %d \n", a, b);
}

int main()

{
    int a, b;
    printf("Enter the two numbers you want to change : ");
    scanf("%d %d", &a, &b);
    printf("Before swapping A is : %d and B is %d \n", a, b);
    swap(a, b);

    return 0;
}