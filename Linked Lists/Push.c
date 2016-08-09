#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void Push(struct node* head, int newData)
{
	struct node* newNode = malloc(sizeof(head));
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
}

main()
{
	struct node* first = malloc(sizeof(first));
	struct node* second = malloc(sizeof(second));
	first->data = 5;
	first->next = second;
	second->data = 3;
	second->next = NULL;

	Push(first, 4);
}