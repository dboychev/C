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

struct node* BuildWithDummyNode()
{
	struct node dummy;
	struct node* tail = &dummy;

	dummy.next = NULL;

	for (int i = 1; i < 6; i++)
	{
		Push(&(tail->next), i);
		tail = tail->next;
	}

	return (dummy.next);
}

main()
{
	BuildWithDummyNode();
}