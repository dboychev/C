#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

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

	printf("%d\n", Count(first, 2));
}