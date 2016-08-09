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

struct node* BuildWithSpecialCase()
{
	struct node* head = NULL;
	struct node* tail;
	
	Push(&head, 1);
	tail = head;

	for (int i = 2; i < 6; i++)
	{
		Push(&(tail->next), i);
		tail = tail->next;
	}
	
	return head;
}

main()
{
	BuildWithSpecialCase();
}