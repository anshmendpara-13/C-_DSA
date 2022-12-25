#include <stdio.h>
#include <conio.h>
int main()
{
    int a;
    printf("Enter the number :");
    scanf("%d", &a);
    int cube = a * a * a;

    printf("cube of a is %d", cube);
    return 0;
}