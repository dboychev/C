#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

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

main()
{
	BuildOneTwoThree();
}