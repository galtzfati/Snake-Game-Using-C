#ifndef List_H
#define List_H
#include <stdio.h>
#include <stdlib.h>
#include "Position.h"

typedef struct listnode {
	struct listnode* next;
	struct listnode* prev;
	Position position;
}ListNode;

typedef struct {
	ListNode* head;
	ListNode* tail;
}List;

void makeEmptyList(List* list);
void insertToHead(List* list, Position position);
void insertToTail(List* list, Position position);
void deleteFromTail(List* list);
void freeList(List* list);

#endif // !List_H