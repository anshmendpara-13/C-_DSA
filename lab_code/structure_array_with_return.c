
#include <stdio.h>
#include <string.h>
struct student
{
    char name[50];
    int A_number;
};

struct student student_information();

int main()
{
    struct student s;

    s = student_information();

    printf("\nDisplaying information\n");
    printf("Your name is : %s", s.name);
    printf("\nYour Roll No is : %d", s.A_number);

    return 0;
}
struct student student_information()
{
    struct student s1;

    printf("Enter name: ");
    scanf("%s", &s1.name);

    printf("Enter A_number: ");
    scanf("%d", &s1.A_number);

    return s1;
}