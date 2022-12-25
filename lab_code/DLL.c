#include <stdio.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next, *pre;
};
int value;
int va;
int vb;
struct node *start = NULL;
int main()
{
    int n;

    while (1)
    {
        printf("\n");
        printf("1.) Insert at begin\n");
        printf("2.) Insert at end\n");
        printf("3.) Insert after value\n");
        printf("4.) Insert before value\n");
        printf("5.) Delete at begin\n");
        printf("6.) Delete at end\n");
        printf("7.) Delete after value\n");
        printf("8.) Delete before value\n");
        printf("9.) Display\n");
        printf("10.) Exit\n");
        printf("Enter you choice : ");
        scanf("%d", &n);
        printf("\n");
        switch (n)
        {
        case 1:

            printf("Enter the value you want to enter : ");
            scanf("%d", &value);
            printf("\n");
            start = insert_at_begin(start, value);
            printf("\n");
            break;
        case 2:
            printf("Enter the value you want to enter : ");
            scanf("%d", &value);
            printf("\n");
            insert_at_end(start, value);
            printf("\n");
            break;
        case 3:
            printf("Enter the value you want to enter : \n");
            scanf("%d", &value);
            printf("Enter the value after you want to enter : ");
            scanf("%d", &va);
            printf("\n");
            insert_after(start, value, va);
            printf("\n");
            break;
        case 4:
            printf("Enter the value you want to enter : \n");
            scanf("%d", &value);
            printf("Enter the value before you want to enter : ");
            scanf("%d", &vb);
            printf("\n");
            insert_before(start, value, vb);
            printf("\n");
            break;
        case 5:
            delete_at_begin();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            printf("Enter the value after you want to delete : ");
            scanf("%d", &va);
            delete_after(start, va);
            break;
        case 8:
            printf("Enter the value before you want to delete : ");
            scanf("%d", &vb);
            delete_before(start, vb);
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Enter the correct choice");
        }
    }
}
void insert_at_begin(struct node *start, int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = start;
    new_node->pre = NULL;
    start = new_node;
}
void insert_at_end(struct node *start, int value)
{
    struct node *ptr;
    ptr = start;
    while ((ptr->next) != NULL)
    {
        ptr = ptr->next;
    }
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->pre = ptr;
    ptr->next = new_node;
}
void insert_after(struct node *start, int value, int va)
{
    struct node *ptr;
    ptr = start;
    while (ptr->data != va)
    {
        ptr = ptr->next;
    }
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = ptr->next;
    ptr->next = new_node;
    new_node->pre = ptr;
}
void insert_before(struct node *start, int value, int vb)
{
    struct node *ptr;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    ptr = start;
    while (ptr->next->data != vb)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    new_node->pre = ptr;
}
void delete_at_begin()
{
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        struct node *ptr;
        ptr = start;
        start = start->next;
        start->pre = NULL;
        printf("the deleted element is: %d", ptr->data);
        free(ptr);
    }
}
void delete_at_end()
{
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        struct node *ptr, *preptr;
        ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        printf("the deleted element is: %d", ptr->data);
        free(ptr);
    }
}
void delete_after(struct node *start, int va)
{
    struct node *ptr;
    struct node *preptr;
    ptr = start;
    preptr = start;
    while (preptr->data != va)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    ptr->next->pre = preptr;
    printf("the deleted element is: %d", ptr->data);
    free(ptr);
}
void delete_before(struct node *start, int vb)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next->data != vb)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    ptr->next->pre = preptr;
    printf("the deleted element is: %d", ptr->data);
    free(ptr);
}
void display()
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
