#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
	int data;
	struct node* next;
};

int Length(struct node* head);

struct node* BuildOneTwoThree();

void Push(struct node** head, int newData);

void DestroyNodeV(int value, struct node* head);
void DestroyNodeP(struct node* node, struct node* head);

struct node* AddAtHead();

struct node* BuildWithSpecialCase();

struct node* BuildWithDummyNode();

struct node* BuildWithLocalRef();

#endif