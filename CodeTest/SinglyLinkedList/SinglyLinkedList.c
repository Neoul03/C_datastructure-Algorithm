#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"

// Create an empty linked list
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

// Free all memories
void freeLinkedList(linkedList_h* L) {
	listNode* temp = L->head;
	listNode* del = NULL;
	
	while (temp != NULL) {
		del = temp;
		temp = temp->link;
		free(del);
	}
	L->head = NULL;
}

// Print all nodes
void print(linkedList_h* L) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) 
	{
		printf("%s ", temp->data);
		temp = temp->link;
	}

	printf("\n");
}

// Insert new node at front
void push_front(linkedList_h* L, char* x) {
	listNode* new_node;
	new_node = (listNode*)malloc(sizeof(listNode));
	strcpy(new_node->data, x);
	new_node->link = L->head;
	L->head = new_node;
}

// Insert new node at back
void push_back(linkedList_h* L, char* x) {
	listNode* new_node;
	new_node = (listNode*)malloc(sizeof(listNode));
	strcpy(new_node->data, x);
	new_node->link = NULL;

	if (L->head == NULL) {
		L->head = new_node;
	}
	else {
		listNode* temp;
		temp = (listNode*)malloc(sizeof(listNode));
		temp = L->head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = new_node;
	}

}

// Insert new node behind pre node
void insert(linkedList_h* L, listNode* pre, char* x) {
	if (pre != NULL) {
		listNode* new_node;
		new_node = (listNode*)malloc(sizeof(listNode));
		strcpy(new_node->data, x);
		if (L->head == NULL) {
			L->head = new_node;
			new_node->link = NULL;
		}
		else {
			new_node->link = pre->link;
			pre->link = new_node;
		}
	}
	else {
		printf("Not found\n");
	}
}

// Delete node p
void erase(linkedList_h* L, listNode* p) {
	if (L->head == NULL) {
		printf("Empty list!\n");
	}
	else {
		if (p != NULL) {
			listNode* pre = L->head;
			while (pre->link != p) {
				pre = pre->link;
			}
			pre->link = p->link;
			free(p);
		}
		else{
			printf("Not found\n");
		}
	}
}

// Delete node at front
void pop_front(linkedList_h* L) {
	if (L->head == NULL) {
		printf("Empty list!\n");
	}
	else{
		listNode* ptr = L->head;
		L->head = L->head->link;
		free(ptr);
	}
}

// Delete node at back
void pop_back(linkedList_h* L) {
	if (L->head == NULL) {
		printf("Empty list!\n");
	}
	else if(L->head->link == NULL){
		free(L->head);
		L->head == NULL;
	}
	else{
		listNode* temp;
		temp = L->head;
		while (temp->link->link != NULL) {
			temp = temp->link;
		}
		listNode* ptr = temp->link;
		temp->link = NULL;
		free(ptr);
	}
}

// Search node which contains x
listNode* find(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while(temp != NULL){
		if (strcmp(temp->data, x) == 0) {
			break;
		}
		else {
			temp = temp->link;
		}
	}
	return temp;
}

// Reverse the order of nodes in list
void reverse(linkedList_h* L) {

	listNode* prev = L->head;
	listNode* curr = NULL;
	listNode* next = NULL;

	if (prev != NULL)
	{
		curr = prev->link;
	}
	else
	{
		return;
	}

	while (curr != NULL) {

		if (curr->link != NULL)
		{
			next = curr->link;
		}
		else
		{
			curr->link = prev;
			L->head->link = NULL;
			L->head = curr;
			break;
		}
		
		curr->link = prev;

		prev = curr;
		curr = next;
	}
}
