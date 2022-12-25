#include <stdio.h>
#include <conio.h>
int main()
{
    int a, b, c, d;

    printf("Enter the first number : ");
    scanf("%d", &a);
    printf("Enter the second number : ");
    scanf("%d", &b);
    c = a / b;
    d = a - (b * c);
    printf("The remainde is %d", d);
    return 0;
}