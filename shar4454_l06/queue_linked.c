/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author ashish sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

/**
 * Initializes a queue.
 *
 * @return - pointer to a new queue
 */
queue_linked* queue_initialize() {

    // your code here
    queue_linked* new_queue = (queue_linked*)malloc(sizeof(queue_linked));

    if (new_queue != NULL) {
        new_queue->front = NULL;
        new_queue->rear = NULL;
        new_queue->count = 0;
    }

    return new_queue;

}


/**
 * Frees queue memory.
 *
 * @param source - pointer to a queue
 */
void queue_free(queue_linked **source) {

    // your code here
    if (*source != NULL) {
        queue_node *current = (*source)->front;
        queue_node *next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }

        free(*source);
        *source = NULL;
    }

}

/**
 * Determines if a queue is empty.
 *
 * @param source - pointer to a queue
 * @return - true if source is empty, false otherwise
 */
BOOLEAN queue_empty(const queue_linked *source) {

    // your code here
    return (source->front == NULL);

}

/**
 * Returns the number of items in a queue.
 *
 * @param source - pointer to a queue
 * @return - the number of items in source
 */
int queue_count(const queue_linked *source) {

    // your code here
    return source->count;

}

/**
 * Pushes a copy of an item onto a queue.
 *
 * @param source - pointer to a queue
 * @param item - pointer to the item to insert
 */
void queue_insert(queue_linked *source, data_ptr item) {

    // your code here
    if (source == NULL || item == NULL) {
	        return;
	    }

	    queue_node *newNode = (queue_node*)malloc(sizeof(queue_node));
	    if (newNode == NULL) {
	        return;
	    }

	    newNode->item = malloc(sizeof(*item));
	    if (newNode->item == NULL) {
	        free(newNode);
	        return;
	    }

	    data_copy(newNode->item, item);

	    newNode->next = NULL;

	    if (source->rear == NULL) {
	        source->front = source->rear = newNode;
	    } else {
	        source->rear->next = newNode;
	        source->rear = newNode;
	    }
	    source->count++;

}

/**
 * Returns a copy of the item on the front of a queue, queue is unchanged.
 *
 * @param source - pointer to a queue
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (queue is empty)
 */
BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {

    // your code here
    if (source == NULL || source->front == NULL) {
	        return FALSE;
	    }
	data_copy(item, source->front->item);
	    return TRUE;

}

/**
 * Removes and returns the item on the front of a queue.
 *
 * @param source - pointer to a queue
 * @param item - pointer the item to remove
 * @return - true if item removeped, false otherwise (queue is empty)
 */
BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {

    // your code here
    if (source->front != NULL) {
        *item = source->front->item;

        queue_node *temp = source->front;
        source->front = temp->next;

        if (source->front == NULL) {
            source->rear = NULL;
        }

        free(temp);

        source->count--;

        return TRUE;

    } else {
        return FALSE;
    }


}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        printf("%s\n", data_string(string, sizeof string, current->item));
        current = current->next;
    }
    return;
}
