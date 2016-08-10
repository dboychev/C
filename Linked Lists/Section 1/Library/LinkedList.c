#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int Length(struct node* head)
{
	int len = 0;
	struct node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	return len;
}

struct node* BuildOneTwoThree()
{
	struct node* first = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));
	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	return first;
}

void Push(struct node** head, int newData)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = *head;
	*head = newNode;
}

//by value
void DestroyNodeV(int value, struct node* head)
{
	struct node* temp = head;
	struct node* prev = NULL;

	if (value == head->data) //if node is the first element
	{
		prev = temp->next;
		head = prev;
	}

	else
	{
		while (temp->data != value && temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp->data == value)
		{
			prev->next = temp->next;
			free(temp);
		}
	}
}

//by pointer
void DestroyNodeP(struct node* node, struct node* head)
{
	struct node* temp = head;
	struct node* prev = NULL;

	if (node == head) //if node is the first element
	{
		prev = temp->next;
		head = prev;
	}

	else
	{
		while (temp != node && temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == node)
		{
			prev->next = temp->next;
			free(temp);
		}
	}
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