/**
 * -------------------------------------
 * @file  queue.c
 *
 * -------------------------------------
 * @author Ashish Sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version 2024-03-02
 *
 * ------------------------------------- */
#include <stdio.h>
#include "queue.h"

/*
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue
 * @param NODE *np - pointer to the node.
 */
void enqueue(QUEUE *qp, NODE *np)
{
    // your code
    if (qp->length == 0)
    {
        qp->front = np;
        qp->rear = np;
        qp->length++;
    }
    else
    {
        qp->rear->next = np;
        qp->rear = np;
        qp->length++;
    }
}

/*
 * Dequeue and return the pointer of the removed node.
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL
 */
NODE *dequeue(QUEUE *qp)
{
    // your code
    NODE *np = qp->front;
    if (qp->length == 0)
    {
        return NULL;
    }
    else if (qp->length == 1)
    {
        qp->front = NULL;
        qp->rear = NULL;
        qp->length--;
        return np;
    }
    else
    {
        qp->front = qp->front->next;
        qp->length--;
        return np;
    }
}

/*
 * Clean the linked list queue
 */
void clean_queue(QUEUE *qp)
{
    clean(&(qp->front));
    qp->front = NULL;
    qp->rear = NULL;
    qp->length = 0;
}
