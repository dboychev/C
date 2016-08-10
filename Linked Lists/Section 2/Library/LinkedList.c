#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int Count(struct node* head, int number)
{
	int count = 0;
	struct node* temp = head;

	while (temp != NULL)
	{
 		if (temp->data == number)
		{
			count++;
		}

		temp = temp->next;
	}

	return count;
}

int GetNth(struct node* head, int index)
{
	struct node* temp = head;
	int i = 0;

	if (index < 0) //Checking if index is too small
	{
		printf("Invalid input!\n");
		return -1;
	}

	while (i < index && temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < index) //Checking if index is too big
	{
		printf("Invalid input!\n");
		return -1;
	}
	return (temp->data);
}

void DeleteList(struct node* head)
{
	struct node* temp = head;
	struct node* prev = temp;

	while (temp->next != NULL) //Changing 'temp' until it points to the last node
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL; //Breaking the connection between the two final nodes

	free(temp);
	if (temp != head)
	{
		DeleteList(head);
	}
}

struct node* Pop(struct node* head)
{
	struct node save = *head;
	free(head);
	return save.data;
}