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

	struct node* head = &first;
	
	struct node* new = malloc(sizeof(struct node));
	new->data = 4;
	new->next = NULL;
	
	struct node* Bfirst = malloc(sizeof(struct node));
	struct node* Bsecond = malloc(sizeof(struct node));
	Bfirst->data = 20;
	Bfirst->next = Bsecond;
	Bsecond->data = 21;
	Bsecond->next = NULL;
	struct node* a = NULL;

	struct node* aList = NULL;
	struct node* bList = NULL;

	/*-----> TEST COUNT <-----
	printf("%d\n", Count(first, 1));*/

	/*-----> TEST GETNTH <-----
	printf("%d\n", GetNth(first, 4));*/

	/*-----> TEST DELETELIST <-----
	DeleteList(head);*/

	/*-----> TEST POP <-----
	printf("%d\n", Pop(head));*/

	/*-----> TEST INSERTNTH <-----
	InsertNth(head, 3, 55);*/

	/*-----> TEST SORTEDINSERT <-----
	SortedInsert(head, new);*/

	/*-----> TEST INSERTSORT
	InsertSort(head);*/

	/*-----> TEST APPEND <-----
	Append(&fourth, &Bfirst);*/

	/*-----> FRONTBACKSPLIT <-----
	FrontBackSplit(*(&second), &front, &back);*/

	/*-----> TEST REMOVEDUPLICATES <-----
	RemoveDuplicates(first);*/

	/*-----> TEST MOVENODE <-----
	MoveNode(&third, &Bfirst);*/

	/*-----> TEST ALTERNATINGSPLIT <-----
	AlternatingSplit(fifth, &aList, &bList);*/

	/*-----> TEST SHUFFLEMERGE <-----
	ShuffleMerge(Bfirst, third);*/

	/*-----> TEST SORTEDMERGE <-----
	SortedMerge(first, Bfirst);*/
	
	/*-----> TEST SORTEDINTERSECT <-----
	SortedIntersect(first, Bfirst);*/

	/*-----> TEST REVERSE <-----
	Reverse(&first);*/
}
