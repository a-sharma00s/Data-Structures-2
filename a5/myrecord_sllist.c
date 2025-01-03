/*
 * your program signature
 Name: Ashish Sharma
 Email: shar4454@mylaurier.ca
 ID: 169044454
 Date: 02/17/2024s
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

/**
 * Search singly linked list by the key name.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE *sll_search(SLL *sllp, char *name)
{
    // your code
    if (sllp == NULL || sllp->start == NULL)
    {
        return NULL;
    }

    NODE *current = sllp->start;
    while (current != NULL)
    {
        if (strcmp(current->data.name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * Insert a new record to linked list at the position sorted by record name field.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - name field of the new record.
 * @param float score - the score data of the new record.
 */
void sll_insert(SLL *sllp, char *name, float score)
{
    // your code
    if (sllp == NULL)
        return;

    NODE *newNode = malloc(sizeof(NODE));
    if (newNode == NULL)
        return;

    strncpy(newNode->data.name, name, sizeof(newNode->data.name) - 1);
    newNode->data.name[sizeof(newNode->data.name) - 1] = '\0';
    newNode->data.score = score;
    newNode->next = NULL;

    if (sllp->start == NULL || strcmp(sllp->start->data.name, name) > 0)
    {
        newNode->next = sllp->start;
        sllp->start = newNode;
    }
    else
    {
        NODE *current = sllp->start;
        while (current->next != NULL && strcmp(current->next->data.name, name) < 0)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    sllp->length++;
}

/**
 * Delete a node of record matched by the name key from linked list.
 *
 * @param SLL *sllp provides the address of a singly linked list structure.
 * @param name - key used to find the node for deletion.
 * @return 1 if deleted a matched node, 0 otherwise.
 */
int sll_delete(SLL *sllp, char *name)
{
    // your code
    if (sllp == NULL || sllp->start == NULL)
    {
        return 0;
    }

    NODE *prev = NULL;
    NODE *current = sllp->start;
    while (current != NULL && strcmp(current->data.name, name) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return 0;
    }
    if (prev == NULL)
    {
        sllp->start = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
    sllp->length--;
    return 1;
}

/**
 * Clean singly linked list, delete all nodes.
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 */
void sll_clean(SLL *sllp)
{
    NODE *temp, *ptr = sllp->start;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}