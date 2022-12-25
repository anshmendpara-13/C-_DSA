// #include <stdio.h>
// #include <stdlib.h>

// struct stack
// {
//     int size;
//     int top;
//     int *arr;
// };

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void createstack(struct stack *s, int size, int top)
// {
//     s->size = 80;
//     s->top = -1;
//     s->arr = (int *)malloc(size * sizeof(int));
//     // s->top++;
//     // s->top = 5;
// }

// int main()
// {
//     struct stack s;
//     createstack(&s, 10, 13);

//     if (isEmpty(&s))
//     {
//         printf("The stack is empty");
//     }
//     else
//     {
//         printf("The stack is not empty");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;

    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top++;
    s->arr[s->top] = 5;

    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }

    return 0;
}