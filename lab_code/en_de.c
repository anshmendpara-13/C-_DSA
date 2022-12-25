#include <stdio.h>
#include <stdlib.h>

#define size 5

int a[size];
int f = -1;
int r = -1;

void enqueue();
void dequeue();
void peek1();
void display();

int main()
{

    int choice;
    while (1)
    {
        printf("\noperations performed : ");
        printf("\n1.enqeue \n2.dequeue \n3.peak \n4.display \n5.exit ");
        printf("\n\n-> Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();

            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek1();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("\n-> Invalid choice!! ");
        }
    }
}

void enqueue()
{
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);

    if (r == size - 1)
    {
        printf("overflow");
    }
    if ((r == -1) && (f == -1))
    {
        f = 0;
        r = 0;
    }
    else
    {
        r++;
    }
    a[r] = x;
}

void dequeue()
{
    if ((r == -1) && (f == -1))
    {
        printf("queue is empty");
    }
    else
    {
        printf("deleted element is : %d ", a[f]);
        f++;
    }
}

void peek1()
{
    if ((r == -1) && (f == -1))
    {
        printf("queue is empty");
    }
    else
    {
        printf("your peak element is %d ", a[f]);
    }
}

void display()
{
    if ((r == -1) && (f == -1))
    {
        printf("queue is empty");
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
