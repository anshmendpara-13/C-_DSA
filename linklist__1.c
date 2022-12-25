#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void insertatbegining();
void display();
void insertatlast();
void insertataftervalue();
void insertatbeforevalue();

struct node *start = NULL;

int main()
{

    while (1)
    {
        printf("\nEnter 1 for insert at begining \n");
        printf("Enter 2 for insert at last \n");
        printf("Enter 3 for insert after value \n");
        printf("Enter 4 for insert before value \n");
        printf("Enter 5 for delete at first \n");
        printf("Enter 6 for deleter at last \n");
        printf("Enter 7 for deleter before value \n");
        printf("Enter 8 for deleter after value \n");
        printf("Enter 9 for search \n");
        printf("Enter 10 for display \n");
        printf("Enter 11 for exit \n");
        // printf("\n");

        int num1;
        printf("\nEnter the operation number you want to perform in linklist : ");
        scanf("%d", &num1);
        switch (num1)
        {
        case 1:
            insertatbegining();
            break;
        case 2:
            insertatlast();
            break;
        case 3:
            insertataftervalue();
            break;
        case 4:
            insertatbeforevalue();
            break;
        // case 5:
        // deleteatfirst();
        //     break;
        // case 6:
        // deleteatlast();
        //     break;
        // case 7:
        // deletebeforevalue();
        //     break;
        // case 8:
        // deleteaftervalue();
        //     break;
        // case 9:
        //     search();
        //     break;
        case 10:
            display();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("invalid input !!!");
        }
    }
    return 0;
}

void insertatbegining()
{
    struct node *new_node;
    int num;
    printf("Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->link = start;
    start = new_node;
}

void insertatlast()
{
    struct node *new_node;
    int num;
    printf("Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->link = NULL;
    struct node *ptr;
    ptr = start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void insertataftervalue()
{
    struct node *new_node;
    int num, data1;
    printf("Enter after the data : ");
    scanf("%d", &num);
    printf("Enter data : ");
    scanf("%d", &data1);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data1;
    new_node->link = NULL;
    struct node *ptr;
    ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void insertatbeforevalue()
{
    struct node *new_node;
    int num, data1;
    printf("Enter before the data : ");
    scanf("%d", &num);
    printf("Enter data : ");
    scanf("%d", &data1);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data1;
    new_node->link = NULL;
    struct node *ptr, *ptr1;
    ptr = start;
    ptr1 = ptr->link;
    while (ptr1->data != num)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    ptr->link = new_node;
    new_node->link = ptr1;
    // ptr = start;
}

void display()
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {

        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    // printf("NULL");
}