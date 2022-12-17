#pragma once

// Node
typedef struct ListNode {
  char data[4];
  struct ListNode* link;
} listNode;

// Header of singly linked list
typedef struct {
  listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList(linkedList_h* L);
void print(linkedList_h* L);
void push_front(linkedList_h* L, char* x);
void push_back(linkedList_h* L, char* x);
void insert(linkedList_h* L, listNode* pre, char* x);
void erase(linkedList_h* L, listNode* p);
void pop_front(linkedList_h* L);
void pop_back(linkedList_h* L);
listNode* find(linkedList_h* L, char* x);
void reverse(linkedList_h* L);
