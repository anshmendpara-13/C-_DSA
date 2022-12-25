#include <stdio.h>
#include <conio.h>

int mult(int y)
{
    int s;
    if (y == 1)
        return (1);
    s = y * mult(y - 1);
    return (s);
}

int main()
{
    int x, o;

    printf("Enter the number : ");
    scanf("%d", &o);

    x = mult(o); // 10*9*8*.......*1
    printf("%d", x);
    return 0;
}
