/*--------------------------------------------------
File:    hash.c
About:   Assignment 9
Author:  Ashish Sharma, 169044454, shar4454@mylaurier.ca
Version:  2024-02-22
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HASHNODE *hashtable_search(HASHTABLE *ht, char *key)
{
    // your code
    int hash_index = hash(key, ht->size);
    HASHNODE *current_node = ht->hna[hash_index];

    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node;
        }
        
        current_node = current_node->next;
    }

    return NULL;
}

int hashtable_insert(HASHTABLE *ht, char *key, int value)
{
    // your code
    int hash_index = hash(key, ht->size);
    HASHNODE *new_node = (HASHNODE *)malloc(sizeof(HASHNODE));

    if (new_node == NULL) {
        printf("Memory allocation failure.\n");
        exit(1);
    }

    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;

    if (ht->hna[hash_index] == NULL) {
        ht->hna[hash_index] = new_node;
    } else {
        HASHNODE *current_node = ht->hna[hash_index];
        HASHNODE *previous_node = NULL;

        while (current_node != NULL && strcmp(current_node->key, key) < 0) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        if (current_node != NULL && strcmp(current_node->key, key) == 0) {
            current_node->value = value;
            free(new_node);
            return 0;
        }

        if (previous_node == NULL) {
            new_node->next = current_node;
            ht->hna[hash_index] = new_node;
        } else {
            previous_node->next = new_node;
            new_node->next = current_node;
        }
    }

    ht->count++;
    return 1;
}

int hashtable_delete(HASHTABLE *ht, char *key)
{
    // your code
    int hash_index = hash(key, ht->size);
    HASHNODE *current_node = ht->hna[hash_index];
    HASHNODE *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            if (previous_node == NULL) {
                ht->hna[hash_index] = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            ht->count--;
            return 1;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
    return 0;
}

int hash(char *key, int size)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash += *key++;
    }
    return hash % size;
}

HASHTABLE *new_hashtable(int size)
{
    HASHTABLE *ht = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    ht->hna = (HASHNODE **)malloc(sizeof(HASHNODE **) * size);
    int i;
    for (i = 0; i < size; i++)
        *(ht->hna + i) = NULL;

    ht->size = size;
    ht->count = 0;
    return ht;
}

void hashtable_clean(HASHTABLE **htp)
{
    if (*htp == NULL)
        return;
    HASHTABLE *ht = *htp;
    HASHNODE *p, *temp;
    int i;
    for (i = 0; i < ht->size; i++)
    {
        p = ht->hna[i];
        while (p)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        ht->hna[i] = NULL;
    }
    free(ht->hna);
    ht->hna = NULL;
    *htp = NULL;
}