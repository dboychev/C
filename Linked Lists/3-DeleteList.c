#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

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

	if (temp != prev) //Checking if 'temp' points to the head node - IF NOT
	{
		free(temp);
		temp = NULL;
		DeleteList(head);
	}

	else //If 'temp' points to the head node - end of recursion
	{
		free(temp);
		temp = NULL;
	}
}

main()
{
	struct node* first = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));
	struct node* fourth = malloc(sizeof(struct node));
	struct node* fifth = malloc(sizeof(struct node));

	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = fourth;
	fourth->data = 2;
	fourth->next = fifth;
	fifth->data = 4;
	fifth->next = NULL;

	DeleteList(first);
}
