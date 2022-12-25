#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
struct node
{
    int data;
    char DOB[15];
    char name[20];
    long long int Ph_no;
    struct node *next;
};

struct node *head;

void lastinsert()
{
    struct node *ptr, *temp;
    char item[15];
    char name1[20];
    long long int Ph_no1;
    int data1;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        int count1 = 0;
        printf("Enter serial number of singer");
        scanf("%d", &data1);
        printf("\nEnter the name of Signer:\n");
        scanf("%s", &name1);

        printf("\nEnter DOB for given singer:\n");
        scanf("%s", &item);

        printf("\nEnter Phone number :\n");
        scanf("%lld", &Ph_no1);
        // printf("%lld",Ph_no1);

        // int Ph=Ph_no;
        // int Ph_no1 = Ph_no;
        // while (Ph_no1 != 0)
        // {
        //     Ph_no1 = Ph_no1 / 10;
        //     if(Ph_no1==0){
        //         count1++;
        //     }
        //     count1++;
        // }
        count1 = (log10(Ph_no1) + 1);

        printf("%d", count1);

        if (count1 != 10)
        {
            printf("Invalid input");
        }
        else
        {
            ptr->data = data1;
            ptr->Ph_no = Ph_no1;
            strcpy(ptr->DOB, item);
            strcpy(ptr->name, name1);

            // printf("%lld",Ph_no1);

            if (head == NULL)
            {
                ptr->next = NULL;
                head = ptr;
                printf("\nNode inserted");
            }

            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->next = NULL;
                printf("\nNode inserted");
            }
        }
    }
}

// void sortList()
// {
//     // Node current will point to head
//     struct node *current = head, *index = NULL;
//     int temp;

//     if (head == NULL)
//     {
//         return;
//     }
//     else
//     {
//         while (current != NULL)
//         {
//             // Node index will point to node next to current
//             index = current->next;

//             while (index != NULL)
//             {
//                 // If current node's data is greater than index's node data, swap the data between them
//                 if (current->data > index->data)
//                 {
//                     temp = current->data;
//                     current->data = index->data;
//                     index->data = temp;
//                 }
//                 index = index->next;
//             }
//             current = current->next;
//         }
//     }
// }

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            printf("\n%s", ptr->name);
            printf("\n%lld", ptr->Ph_no);
            printf("\n%s", ptr->DOB);
            free(ptr);
            ptr = ptr->next;
        }
    }
}
void functionforDOB()
{
    int choice, flag = 1;
    while (flag)
    {
        printf("\nEnter your choice?\n");
        printf("\n1.Insert the data of Singer\n2.To see list of Singer\n3.Exit\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            lastinsert();
            break;

        case 2:
            display();
            break;

        case 3:
            flag = 0;
            break;

        default:
            printf("Invalid choice");
        }
    }
}

// void sort(struct node **h)
// {
//     int i, j, a, b;
//     char t[20];

//     struct node *temp1;
//     struct node *temp2;

//     for (temp1 = *h; temp1 != NULL; temp1 = temp1->next)
//     {
//         for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
//         {
//             a = temp1->data;
//             temp1->data = temp2->data;
//             temp2->data = a;

//             i = temp1->Ph_no;
//             temp1->Ph_no = temp2->Ph_no;
//             temp2->Ph_no = i;

//             strcpy(t, temp1->name);
//             strcpy(temp1->name, temp2->name);
//             strcpy(temp2->name, t);

//             strcpy(t, temp1->DOB);
//             strcpy(temp1->DOB, temp2->DOB);
//             strcpy(temp2->DOB, t);
//         }
//     }
// }

int main()
{

    functionforDOB();
    // sort(&head);
    return 0;
}