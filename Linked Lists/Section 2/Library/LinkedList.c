#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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

int GetNth(struct node* head, int index)
{
	struct node* temp = head;
	int i = 0;

	if (index < 0) //Checking if index is too small
	{
		printf("Invalid input!\n");
		return -1;
	}

	while (i < index && temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < index) //Checking if index is too big
	{
		printf("Invalid input!\n");
		return -1;
	}
	return (temp->data);
}

void DeleteList(struct node** head)
{
	struct node* temp = *head;
	struct node* prev = temp;

	while (temp->next != NULL) //Changing 'temp' until it points to the last node
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL; //Breaking the connection between the two final nodes

	free(temp);
	if (temp != *head)
	{
		DeleteList(head);
	}
}

int Pop(struct node** head)
{
	int hData = (*head)->data;
	struct node* newNode = NULL;

	if (head == NULL)
	{
		return -1;
	}

	newNode = (*head)->next;
	free(*head);
	return hData;
}

void InsertNth(struct node** headRef, int index, int data)
{
	struct node* temp = *headRef;
	int i = 0;

	if (index < 0)
	{
		printf("Invalid index value!\n");
		return;
	}
	while (i < index)
	{
		if (temp->next != NULL) //A test for the case if 'newNode' has to be the last node
		{
			temp = temp->next;
		}
		i++;
	}

	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;

	if (index == 0) //If 'newNode' has to be the first element in the list
	{
		newNode->next = temp;
		*headRef = newNode; //'newNode' is the new head element
	}
	
	else 
	{
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void swap(struct node* a, struct node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void SortedInsert(struct node** headRef, struct node* newNode)
{
	struct node* ptr1 = *headRef; //Creating two pointers for easy swapping
	struct node* ptr2 = ptr1->next;

	while (ptr1 != NULL) 
	{
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
			{
				swap(ptr1, ptr2);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
 		if (ptr2 == NULL && ptr1 != NULL)
		{
 			ptr2 = ptr1->next;
		}
	}

	int index = 0;
	ptr1 = *headRef; //Using 'ptr1' again, this time for finding the correct place for the new node
	while (ptr1->data < newNode->data)
	{
		ptr1 = ptr1->next;
		index++;
	}

	InsertNth(headRef, index, newNode->data);
}

void InsertSort(struct node** headRef)
{
	struct node* temp = *headRef;
	SortedInsert(headRef, temp); //Sorting and adding the head element to the already sorted list
	
	//Pop(headRef); //Removing the first element in the list that was just added
	
	temp = *headRef; //Changing 'temp' to the head element again
	*headRef = temp->next; //'headRef' now points to the second element
	free(temp); //Clearing the first element
}

void Append(struct node** aRef, struct node** bRef)
{
  	struct node* aPtr = *aRef;
	struct node* bPtr = *bRef;

	if (aPtr != NULL) //Checking if list 'a' is empty
	{
		while (aPtr->next != NULL) 
		{
			aPtr = aPtr->next;
		}
	}
	
	while (bPtr != NULL)
	{
		struct node* new = malloc(sizeof(struct node)); //Adding elements of 'b' list to 'a' 1 by 1
		new->data = bPtr->data;
		new->next = NULL;
		if (aPtr == NULL) //If 'a' is empty
		{
			aPtr = new;
			bPtr = bPtr->next;
		}
		else
		{
			aPtr->next = new;
			bPtr = bPtr->next;
			aPtr = aPtr->next;
		}
	}

	free(*bRef); //Clearing list 'b' 
}

void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
	struct node* temp = source;
	if (temp == NULL) //A test if the list is empty
	{
		printf("Error!!! Source list is empty!\n");
		return;
	}

	int len = 0; //A variable for the length of the list
	while (temp != NULL)
	{
 		temp = temp->next;
		len++;
	}
	temp = source;

  	*frontRef = source;
	for (int i = 0; i < len / 2 + len % 2 - 1; i++)
	{
		temp = temp->next;
	}

	*backRef = temp->next; //That is the first element after the half of the list - goes to the 'back'
	temp->next = NULL; //Cutting the connection between the 'front' and the nodes that should not be in it
}

void RemoveDuplicates(struct node* head)
{
	struct node* left = head;
	struct node* right = left->next;
	struct node* temp = head;
	struct node* temp2 = head;

	while (left != NULL)
	{
		while (right != NULL)
		{
			if (left->data == right->data) //If same elements found
			{
				temp = right;
				temp2 = left;
				while (temp2->next != right)
				{
					temp2 = temp2->next;
				}
				right = right->next;
				temp2->next = right;
				free(temp); 
			}
			else
			{
				right = right->next;
			}
		}
		left = left->next;
		if (left != NULL)
		{
			right = left->next;
		}
	}

	//InsertSort(&head);

	left = head;
	right = left->next;

	while (left != NULL) //Sorting
	{
		while (right != NULL)
		{
			if (left->data > right->data)
			{
				swap(left, right);
			}

			right = right->next;
		}

		left = left->next;
		if (left != NULL && right == NULL)
		{
			right = left->next;
		}
	}
}

void MoveNode(struct node** destRef, struct node** sourceRef)
{
	struct node* dTemp = *destRef;
	struct node* sTemp = *sourceRef;

	*sourceRef = (*sourceRef)->next;
	sTemp->next = dTemp;
	*destRef = sTemp;
}

void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef)
{
	struct node* aTemp = source;
	struct node* bTemp = source->next;

	*aRef = source; //'aRef' points to the first element of the list
	*bRef = source->next; //'bRef' points to the second element of the list

	while (aTemp != NULL && bTemp != NULL)
	{
		aTemp->next = bTemp->next; //Skipping one element in the A list
		aTemp = aTemp->next;
	
		bTemp->next = aTemp->next; //Skipping one element in the B list
		bTemp = bTemp->next;
	}
}

void ShuffleMerge(struct node* a, struct node* b)
{
	struct node* head = malloc(sizeof(struct node));
	struct node* aTemp = a;
	struct node* bTemp = b;
	struct node* headSAVE = malloc(sizeof(struct node));

	if (a == NULL) //If 'a' list is empty
	{
		head = b;
	}

	else if (b == NULL) //If 'b' list is empty
	{
		head = a;
	}

	else //If both 'a' and 'b' list have nodes
	{
		head = a; //The new list starts with the head element of 'a' list
		headSAVE = head; //'headSAVE' - here will be save the head element of the new list
		aTemp = a->next; //'aTemp' - helping to get to the next element of the 'a' list

		head->next = b; //Connecting the elements of 'a' and 'b' one by one
 		head = head->next; 
		bTemp = bTemp->next; //'bTemp' - helping to get to the next element of the 'b' list

		while (aTemp != NULL && bTemp != NULL) //While both lists have any nodes left
		{
			head->next = aTemp; 
			aTemp = aTemp->next;
			head = head->next; 
			head->next = bTemp;
			bTemp = bTemp->next;
			head = head->next;
		} //When the 'while' stops it means at least one of the lists has no more nodes left

		if (aTemp != NULL) //If 'b' has no more nodes, but 'a' is still not empty
		{
			head->next = aTemp; //Connecting the nodes left in 'a' list to the last node of the new list
		}

		if (bTemp != NULL) //If 'a' has no more nodes, but 'b' is still not empty
		{
			head->next = bTemp; //Connecting the nodes left in 'b' list to the last node of the new list
		}

		head = headSAVE; //Making 'head' point to the first node of the new list 
	}
}

struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node* head = malloc(sizeof(struct node));
	struct node* headSAVE = head; //'headSAVE' - used for pointing the head node of the list

	while (a != NULL && b != NULL) //If both lists are not empty
	{
		if (a->data <= b->data) //Comparing the next 'a' node vs the next 'b' node
		{
 			head->next = a;
			a = a->next;
		}

		else
		{
			head->next = b;
			b = b->next;
		}

		head = head->next;
	} //If that 'while' ends, it means at least one of the lists is empty 

	if (a != NULL) //If 'a' still has any nodes left
	{
		head->next = a; //Connecting the nodes left to the final node of the new list
	}

	if (b != NULL) //If 'b' still has any nodes left
	{
		head->next = b; //Connecting the nodes left to the final node of the new list
	}

	headSAVE = headSAVE->next; //Making headSAVE to point to the first real node
	return headSAVE;
}

struct node* SortedIntersect(struct node* a, struct node* b)
{
	struct node* head = malloc(sizeof(struct node));
	struct node* headSAVE = head;
	struct node* new = malloc(sizeof(struct node));
	struct node* aTemp = a;
	struct node* bTemp = b;
	int count = 0;

	while (aTemp != NULL)
	{
		while (bTemp != NULL)
		{
			if (aTemp->data == bTemp->data)
			{
				if (count > 0)
				{
					struct node* new = malloc(sizeof(struct node));
					new->data = aTemp->data;
					new->next = NULL;
					head->next = new;
					head = head->next;
				}

				else
				{
					head->data = aTemp->data;
				}

				count++;
			}

			bTemp = bTemp->next;
		}

		aTemp = aTemp->next;
		bTemp = b;
	}
	
	return headSAVE;
}