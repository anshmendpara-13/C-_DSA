#include <stdio.h>
#include <stdlib.h>

#define size 4

int top = -1;
char array[size];
void push();
void pop();
void peek1();
char peek(char array[]);
void show();
void peep();

int main()
{

    int choice;
    while (1)
    {
        printf("\noperations performed by stack ");
        printf("\n1.Push the element\n2.Pop the element\n3.peek the element\n4.peep the element\n5.Show\n6.End");
        printf("\n\n-> Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek1();
            break;
        case 4:
            peep();
            break;
        case 5:
            show();
            break;
        case 6:
            exit(0);

        default:
            printf("\n-> Invalid choice!! ");
        }
    }
}

void push()
{
    // int x;
    char x;
    if (top == size - 1)
    {
        printf("stack is overflow!!");
    }
    printf("\n-> Enter elemente to be inserted to the array : ");
    scanf(" %c", &x);
    top = top + 1;
    array[top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("\n-> Underflow!!");
    }
    printf("\n-> popped element is %c", array[top]);
    top = top - 1;
}

void show()
{

    if (top == -1)
    {
        printf("\n-> Underflow!!");
    }
    else
    {
        printf("\n-> Elements present in the array : \n");
        for (int i = top; i >= 0; --i)
        {
            printf("%c\n", array[i]);
        }
    }
}

void peek1()
{
    top = peek(array);
    if (top != -1)
    {
        printf("\n-> The value stored at top of array is %s ", top);
    }
}

char peek(char array[])
{
    if (top == -1)
    {
        printf("\n-> array is empty ");
        return -1;
    }
    else
    {
        return (array[top]);
    }
}

void peep()
{
    char p;
    printf("\nEnter the position : ");
    scanf("%s", &p);
    if (top - p <= -1)
    {
        printf("\narray is overflow !!!");
    }
    else
    {
        printf("\nThe Elements is : %c", array[top - p + 1]);
    }
}