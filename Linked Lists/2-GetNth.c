#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

int GetNth(struct node* head, int index)
{
	struct node* temp = head;
	int i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp->data);
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

	printf("%d\n", GetNth(first, 0));
}