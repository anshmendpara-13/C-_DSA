#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[30];
    int age;
    
};

int main()
{
    struct student *ptr;
    int i, n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    ptr = (struct student *)malloc(n * sizeof(struct student));

    for (i = 0; i < n; ++i)
    {
        printf("Enter first name and age respectively: ");

        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }

    printf("Displaying Information:\n");
    for (i = 0; i < n; ++i)
        printf("Name: %s And Age: %d\n", (ptr + i)->name, (ptr + i)->age);

    return 0;
}