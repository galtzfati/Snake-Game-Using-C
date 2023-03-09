#ifndef List_C
#define List_C
#include "List.h"

void makeEmptyList(List* list) {
	list->head = NULL;
	list->tail = NULL;
}
void insertToHead(List* list, Position position) {
    // Create a new node and set its fields
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        system("cls");
        printf("Memory allocation error. Exiting...");
        exit(1);
    }
    newNode->position = position;
    newNode->prev = NULL;

    // If the list is empty, set the new node as both the head and tail
    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        // Otherwise, insert the new node at the head of the list
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}
void insertToTail(List* list, Position position) {
    // Create a new node and set its fields
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        system("cls");
        printf("Memory allocation error. Exiting...");
        exit(1);
    }
    newNode->position = position;
    newNode->next = NULL;

    // If the list is empty, set the new node as both the head and tail
    if (list->tail == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        // Otherwise, insert the new node at the tail of the list
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}
void deleteFromTail(List* list) {
    // Check if the list is empty
    if (list->tail == NULL) {
        return;
    }

    // Get the tail node and its position
    ListNode* tailNode = list->tail;

    // If the list has only one node, set both head and tail to NULL
    if (tailNode->prev == NULL) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        // Otherwise, update the tail pointer and unlink the tail node
        list->tail = tailNode->prev;
        list->tail->next = NULL;
    }

    free(tailNode);
}
void freeList(List* list) {
    ListNode* curr = list->head;
    ListNode* prevCurr;
    while (curr != NULL) {
        prevCurr = curr;
        curr = curr->next;
        free(prevCurr);
    }
}

#endif // !List_C