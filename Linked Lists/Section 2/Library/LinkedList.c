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

void DeleteList(struct node** head)
{
	struct node* temp = *head;
	struct node* prev = temp;

	while (temp->next != NULL) //Changing 'temp' until it points to the last node
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL; //Breaking the connection between the two final nodes

	free(temp);
	if (temp != *head)
	{
		DeleteList(head);
	}
}

int Pop(struct node** head)
{
	int hData = (*head)->data;
	struct node* newNode = NULL;

	if (head == NULL)
	{
		return -1;
	}

	newNode = (*head)->next;
	free(*head);
	return hData;
}

void InsertNth(struct node** headRef, int index, int data)
{
	struct node* temp = *headRef;
	int i = 0;

	while (i < index)
	{
		if (temp->next != NULL) //A test for the case if 'newNode' has to be the last node
		{
			temp = temp->next;
		}
		i++;
	}

	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;

	if (index == 0) //If 'newNode' has to be the first element in the list
	{
		newNode->next = temp;
		*headRef = newNode; //'newNode' is the new head element
	}
	
	else 
	{
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void swap(struct node* a, struct node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void SortedInsert(struct node** headRef, struct node* newNode)
{
	struct node* ptr1 = *headRef; //Creating two pointers for easy swapping
	struct node* ptr2 = ptr1->next;

	while (ptr1 != NULL) 
	{
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
			{
				swap(ptr1, ptr2);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
 		if (ptr2 == NULL && ptr1 != NULL)
		{
 			ptr2 = ptr1->next;
		}
	}

	int index = 0;
	ptr1 = *headRef; //Using 'ptr1' again, this time for finding the correct place for the new node
	while (ptr1->data < newNode->data)
	{
		ptr1 = ptr1->next;
		index++;
	}

	InsertNth(headRef, index, newNode->data);
}