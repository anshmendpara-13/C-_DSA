#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *ptr, *preptr;

void insert_beg()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data : ");
    scanf("%d", &d);
    ptr->data = d;
    ptr->link = NULL;
    if (head == NULL)
    {
        head = ptr;
        ptr->link = head;
    }
    else
    {
        preptr = head;
        while (preptr->link != head)
        {
            preptr = preptr->link;
        }
        ptr->link = head;
        preptr->link = ptr;
        head = ptr;
    }
}
void insert_end()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data : ");
    scanf("%d", &d);
    ptr->data = d;
    ptr->link = NULL;
    if (head == NULL)
    {
        head = ptr;
        ptr->link = head;
    }
    else
    {
        preptr = head;
        while (preptr->link != head)
        {
            preptr = preptr->link;
        }
        preptr->link = ptr;
        ptr->link = head;
    }
    printf("\nINSERTED");
}

void display()
{
    if (head == NULL)
    {
        printf("\nCLL EMPTY");
    }
    else
    {
        ptr = head;
        printf("%d ", ptr->data);
        while (ptr->link != head)
        {
            ptr = ptr->link;
            printf("%d ", ptr->data);
        }
    }
}
void delete_beg()
{
    if (head == NULL)
    {
        printf("\nSLL EMPTY");
    }
    else
    {
        ptr = head;
        while (ptr->link != head)
        {
            ptr = ptr->link;
        }
        ptr->link = head->link;
        free(head);
        head = ptr->link;
    }
    printf("\nDeleted");
}
void delete_end()
{
    if (head == NULL)
    {
        printf("\nSLL EMPTY");
    }
    else
    {
        ptr = head;
        while (ptr->link != head)
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        preptr->link = head;
        free(ptr);
    }
    printf("\nDeleted");
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("\n%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n1.insert at beginning");
            printf("\n2.insert at end");
            printf("\n3.Exit");
            printf("\nEnter your choice : ");
            scanf("\n%d", &ch);
            switch (ch)
            {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                exit(0);
            }
            break;
        case 2:
            printf("\n1.delete at beginning");
            printf("\n2.delete at end");
            printf("\n3.Exit");
            printf("\nEnter your choice : ");
            scanf("\n%d", &ch);
            switch (ch)
            {
            case 1:
                delete_beg();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                exit(0);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}