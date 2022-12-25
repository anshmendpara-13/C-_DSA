#include <stdio.h>
#include <conio.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("This number is negative");
    }
    else if (n == 0)
    {
        printf("number is zero");
    }
    else
    {
        printf("This number is positive");
    }
    return 0;
}