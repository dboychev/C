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

	first->data = 2;
	first->next = second;
	second->data = 1;
	second->next = third;
	third->data = 5;
	third->next = fourth;
	fourth->data = 4;
	fourth->next = fifth;
	fifth->data = 3;
	fifth->next = NULL;

	struct node* head = &first;

	//printf("%d\n", Count(first, 1));

	//printf("%d\n", GetNth(first, 4));

	//DeleteList(head);

	//printf("%d\n", Pop(head));

	//InsertNth(head, 3, 55);

	/*struct node* new = malloc(sizeof(struct node));
	new->data = 4;
	new->next = NULL;
	SortedInsert(head, new);*/

	//InsertSort(head);

	struct node* Bfirst = malloc(sizeof(struct node));
	struct node* Bsecond = malloc(sizeof(struct node));
	Bfirst->data = 20;
	Bfirst->next = Bsecond;
	Bsecond->data = 21;
	Bsecond->next = NULL;
	struct node* a = NULL; //Test for an empty list
	Append(&fourth, &Bfirst);
}