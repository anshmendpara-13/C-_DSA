#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int a[SIZE];
int front = -1;
int rear = -1;
void enqueue(int k);
void dequeue();

int main()
{
	int choice, x;
	while (1)
	{
		printf("\nOperation Of Queue");
		printf("\nEnter 1 for Enqueue");
		printf("\nEnter 2 for Dequeue");
		printf("\nEnter 3 for Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter Elements:");
			scanf("%d", &x);
			enqueue(x);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			exit(1);
			break;

		default:
			printf("Enter the valid choice.");
		}
	}
	return 0;
}
void enqueue(int k)
{
	if ((rear + 1) % SIZE == front)
	{
		printf("\nQueue is overflow.");
	}
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else if (front != 0)
	{
		rear = 0;
	}
	else
	{
		rear = (rear + 1) % SIZE;
	}
	a[rear] = k;
}
void dequeue()
{
	int data = a[front];
	if (front == -1)
	{
		printf("\nQueue is underflow.\n");
	}
	printf("\ndeleted element:%d", data);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == (SIZE - 1))
		{
			front = 0;
		}
		else
		{
			front = (front + 1) % SIZE;
		}
	}
}
