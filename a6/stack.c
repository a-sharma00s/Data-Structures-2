/**
 * -------------------------------------
 * @file  stack.c
 *
 * -------------------------------------
 * @author Ashish Sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version 2024-03-02
 *
 * ------------------------------------- */
#include <stdio.h>
#include "stack.h"

/*
 * Define a structure STACK containing the length and pointer of the top node.
 * int length - maintains the length of stack.
 * NODE *top - pointer to the top node of linked list stack
 */
void push(STACK *sp, NODE *np)
{
    // your code
    if (sp->length == 0)
    {
        sp->top = np;
        sp->length++;
    }
    else
    {
        np->next = sp->top;
        sp->top = np;
        sp->length++;
    }
}

/*
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 */
NODE *pop(STACK *sp)
{
    // your code
    NODE *np = sp->top;
    if (sp->length == 0)
    {
        return NULL;
    }
    else if (sp->length == 1)
    {
        sp->top = NULL;
        sp->length--;
        return np;
    }
    else
    {
        sp->top = sp->top->next;
        sp->length--;
        return np;
    }
}

/*
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL
 */
void clean_stack(STACK *sp)
{
    clean(&(sp->top));
    sp->top = NULL;
    sp->length = 0;
}