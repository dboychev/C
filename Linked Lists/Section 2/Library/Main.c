#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
	fourth->data = 4;
	fourth->next = fifth;
	fifth->data = 5;
	fifth->next = NULL;

	printf("%d\n", Count(first, 2));

	printf("%d\n", GetNth(first, 4));

	DeleteList(first);

	printf("%d\n", Pop(first));
}