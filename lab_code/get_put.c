#include <stdio.h>
#include <string.h>
struct student
{
    char name[20];
    int A_number;
};

struct student student_information();

int main()
{
    struct student s;

    s = student_information();

    return 0;
}
struct student student_information()
{
    struct student s1;

    printf("Enter name: ");
    scanf("%s", &s1.name);

    printf("Enter A_number: ");
    scanf("%d", &s1.A_number);

    printf("Your name is : %s\n", s1.name);
    printf("Your roll nubmer is : %d\n", s1.A_number);
}
/*
OUTPUT
======


*/

