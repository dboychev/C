#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

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

main()
{
	struct node* first = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));
	struct node* fourth = malloc(sizeof(struct node));
	first->data = 1;
	first->next = second;
	second->data = 5;
	second->next = third;
	third->data = 10;
	third->next = fourth;
	fourth->data = first->data + second->data;
	fourth->next = NULL;
	
	printf("%d\n", Length(first));
}