#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

void Push(struct node** head, int newData)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = *head;
 	*head = newNode;
}

struct node* AddAtHead()
{
	struct node* head = NULL;

	for (int i = 0; i < 6; i++)
	{
		Push(&head, i);
	}

	return head;
}

main()
{
	AddAtHead();
}