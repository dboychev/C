#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

int Length(struct node* head)
{
	int len = 1;
	while (head->next != NULL)
	{
		head->next = head->next->next;
		len++;
	}

	return len;
}

main()
{
	struct node first;
	struct node second;
	struct node third;
	struct node fourth;
	first.data = 1;
	first.next = &second;
	second.data = 5;
	second.next = &third;
	third.data = 10;
	third.next = &fourth;
	fourth.data = first.data + second.data;
	fourth.next = NULL;
	
	printf("%d\n", Length(&first));
}