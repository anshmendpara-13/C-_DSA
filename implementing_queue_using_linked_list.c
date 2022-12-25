#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    printf("printing the element of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element :%d", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)

        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedlisttraversal(f);
    printf("dequeuing element %d\n", dequeue());
    enqueue(13);
    enqueue(103);
    enqueue(113);
    enqueue(153);
    printf("dequeuing element %d\n", dequeue());
    printf("dequeuing element %d\n", dequeue());
    printf("dequeuing element %d\n", dequeue());
    printf("dequeuing element %d\n", dequeue());
    linkedlisttraversal(f);
    return 0;
}