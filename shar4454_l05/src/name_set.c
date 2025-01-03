/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set *name_set_initialize()
{
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

/**
 * Frees all of the nodes in the set, including the header node.
 * Returns a count of the number of nodes freed, including the header node.
 *
 * @param set - pointer to an initialized name_set
 * @return number of nodes freed
 */
int name_set_free(name_set **set)
{

    // your code here
    int count = 0;

	if (set == NULL || *set == NULL) {
		return count;
	}

	name_set_node *current = (*set)->front;
	while (current != NULL) {
		name_set_node *temp = current;
		current = current->next;
		free(temp);
		count++;
	}
	free(*set);
	*set = NULL;

	return count;
}

/**
 * Appends a name to a name_set, but only if the name is not already present in the set.
 * That is, only unique names are inserted.
 *
 * @param set - pointer to an initialized name_set
 * @param first_name - a first name string
 * @param last_name - a last name string
 * @return TRUE if the name was appended, FALSE otherwise
 */
BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name)
{

    // your code here
    if (set == NULL)
        return FALSE;

    name_set_node *current = set->front;
    while (current != NULL)
    {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->last_name, last_name) == 0)
        {
            return FALSE;
        }
        current = current->next;
    }

    name_set_node *newNode = malloc(sizeof(name_set_node));
    if (newNode == NULL)
    {
        return FALSE;
    }

    strncpy(newNode->first_name, first_name, NAME_LEN);
    newNode->first_name[NAME_LEN - 1] = '\0';
    strncpy(newNode->last_name, last_name, NAME_LEN);
    newNode->last_name[NAME_LEN - 1] = '\0';
    newNode->next = NULL;

    if (set->rear != NULL)
    {
        set->rear->next = newNode;
    }

    if (set->front == NULL)
    {
        set->front = newNode;
    }
    set->rear = newNode;
    return TRUE;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name)
{

    // your code here
    if (set == NULL)
        return FALSE;

    name_set_node *current = set->front;
    while (current != NULL)
    {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->last_name, last_name) == 0)
        {
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}

/**
 * Print the contents of the linked set of names, one name per line in the format:
 * last name, first name
 * ex:
 * Brown, David
 *
 * @param set - pointer to an initialized name_set
 */
void name_set_print(const name_set *set)
{

    // your code here
    if (set == NULL)
    {
        return;
    }

    name_set_node *curr = set->front;
    while (curr != NULL)
    {
        printf("%s, %s\n", curr->last_name, curr->first_name);
        curr = curr->next;
    }
}
