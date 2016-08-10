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

struct node* BuildWithLocalRef()
{
	struct node* head = NULL;
	struct node** lastPtrRef = &head;
	
	for (int i = 1; i < 6; i++)
	{
		Push(lastPtrRef, i);
		lastPtrRef = &((*lastPtrRef)->next);
	}

	return (head);
}


main()
{
	BuildWithLocalRef();
}