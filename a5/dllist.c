/*
 * your program signature
 Name: Ashish Sharma
 Email: shar4454@mylaurier.ca
 ID: 169044454
 Date: 02/17/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE *new_node(char value)
{
    // your code
    NODE *node = (NODE*) malloc(sizeof(NODE));

	if (node == NULL)
		return NULL;

	node->data = value;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

void dll_insert_start(DLL *dllp, NODE *np)
{
    // your code
    if (dllp == NULL || np == NULL) {
        return;
    }

    if (dllp->start == NULL) {
        dllp->start = dllp->end = np;
    } else {
        np->next = dllp->start;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
    
}

void dll_insert_end(DLL *dllp, NODE *np)
{
    // your code
    if (dllp == NULL || np == NULL) {
        return;
    }

    np->next = NULL;
    np->prev = dllp->end;

    if (dllp->start == NULL) {
        dllp->start = dllp->end = np;
    } else {
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
    
}

void dll_delete_start(DLL *dllp)
{
    // your code
    if (dllp == NULL || dllp->start == NULL) {
        return;
    }

    NODE *temp = dllp->start;
    if (dllp->start == dllp->end) {
        dllp->start = dllp->end = NULL;
    } else {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }
    free(temp);
    dllp->length--;
}

void dll_delete_end(DLL *dllp)
{
    // your code
    if (dllp == NULL || dllp->end == NULL) {
        return;
    }

    NODE *temp = dllp->end;
    if (dllp->start == dllp->end) {
        dllp->start = dllp->end = NULL;
    } else {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }
    free(temp);
    dllp->length--;
}

void dll_clean(DLL *dllp)
{
    // your code
    NODE *current = dllp->start;
    while (current != NULL) {
        NODE *temp = current;
        current = current->next;
        free(temp);
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}
