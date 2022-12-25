#include <stdio.h>
#include <conio.h>
int main()
{
    int a;
    printf("Enter the nubmer : ");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("a is even number");
    }
    else
    {

        printf("a is odd number");
    }
    return 0;
}