#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree()
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
	return &first;
}

main()
{
	BuildOneTwoThree();
}