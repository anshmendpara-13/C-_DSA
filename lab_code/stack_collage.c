#include <stdio.h>
#include <stdlib.h>

#define size 5

int top = -1, array[size];
void push();
void pop();
void peek1();
int peek(int array[]);
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
    int x;
    if (top == size - 1)
    {
        printf("stack is overflow!!");
    }
    printf("\n-> Enter elemente to be inserted to the array : ");
    scanf("%d", &x);
    top = top + 1;
    array[top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("\n-> Underflow!!");
    }
    printf("\n-> popped element is %d", array[top]);
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
            printf("%d\n", array[i]);
        }
    }
}

void peek1()
{
    top = peek(array);
    if (top != -1)
    {
        printf("\n-> The value stored at top of array is %d ", top);
    }
}

int peek(int array[])
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
    int p;
    printf("\nEnter the position : ");
    scanf("%d", &p);
    if (top - p <= -1)
    {
        printf("\narray is overflow !!!");
    }
    else
    {
        printf("\nThe Elements is : %d", array[top - p + 1]);
    }
}