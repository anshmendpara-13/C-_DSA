#include <stdio.h>
struct student
{
    char name[10];
    int Percentage, Roll_No;
};

void display(int a, int b);

int main()
{
    struct student s1;

    printf("Enter name : ");
    gets(s1.name);
    printf("Enter the roll number : ");
    scanf("%d", &s1.Roll_No);
    printf("Enter percentage : ");
    scanf("%d", &s1.Percentage);
    display(s1.Roll_No, s1.Percentage);
    return 0;
}

void display(int a, int b)
{
    printf("\nDisplaying information\n");
    printf("Roll number : %d", a);
    printf("\nPercentage : %d%% ", b);
}