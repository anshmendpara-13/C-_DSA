#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self referencing structure
};

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    return 0;
}