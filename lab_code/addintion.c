#include <stdio.h>
#include <conio.h>
int main()
{
    int n;
    int sum = 0;
    int a;
    printf("Enter the number you want to add : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number : ");
        scanf("%d", &a);
        sum = sum + a;
    }
    printf("%d", sum);

    return 0;
}