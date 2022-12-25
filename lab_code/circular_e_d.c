#include <stdio.h>
#include <stdlib.h>

#define size 10

int a[size];
int f = -1;
int r = -1;

void enqueue();
void dequeue();
// void display();

int main()
{

    int choice;
    while (1)
    {
        printf("\noperations performed : ");
        printf("\n1.enqeue \n2.dequeue \n3.display \n4.exit ");
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

            // case 3:
            //     display();

        case 4:
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
    if ((r + 1) % size == f)
    {
        printf("queue is full");
    }
    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
    }
    else if ((size - 1) && (f != 0))
    {
        r = 0;
    }
    else
    {
        r = (r + 1) % size;
    }
    a[r] = x;
}

// void display()
// {
//     int i;
//     if (f == -1)
//         printf(" \n Empty Queue\n");
//     else
//     {
//         printf("\n Front -> %d ", f);
//         printf("\n Items -> ");
//         for (i = f; i != r; i = (i + 1) % size)
//         {
//             printf("%d ", a[i]);
//         }
//         printf("%d ", a[i]);
//         printf("\n Rear -> %d \n", r);
//     }
// }

void dequeue()
{
    if ((f == -1))
    {
        printf("queue is empty");
    }
    printf("deleted element is %d ", a[f]);

    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        if (f == (size - 1))
        {
            f = 0;
        }
        else
        {
            f = (f + 1) % size;
        }
    }
}
