#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
	int data;
	struct node* next;
};

int Count(struct node* head, int number);

int GetNth(struct node* head, int index);

void DeleteList(struct node** head);

int Pop(struct node** head);

void InsertNth(struct node** headRef, int index, int data);

#endif
