#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

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

main()
{
	struct node* first = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));
	struct node* fourth = malloc(sizeof(struct node));
	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = fourth;
	fourth->data = 4;
	fourth->next = NULL;

	DestroyNodeV(3, first);
	DestroyNodeP(fourth, first);
}