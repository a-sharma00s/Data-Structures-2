/**
 * -------------------------------------
 * @file  expression.c
 *
 * -------------------------------------
 * @author Ashish Sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version 2024-03-02
 *
 * ------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

QUEUE infix_to_postfix(char *infixstr)
{
    // your code
    char *p = infixstr;
    QUEUE queue = {0};
    STACK stack = {0};
    int sign = 1, num = 0;
    while (*p)
    {
        if (*p == '-' && (p == infixstr || *(p - 1) == '('))
        {
            sign = -1;
        }
        else if (get_type(*p) == 0)
        {
            num = *p - '0';
            while ((*(p + 1) >= '0' && *(p + 1) <= '9'))
            {
                num = num * 10 + *(p + 1) - '0';
                p++;
            }
            enqueue(&queue, new_node(sign * num, 0));
            sign = 1;
        }
        else if (get_type(*p) == 1)
        {
            while (stack.top && get_priority(stack.top->data) >= get_priority(*p))
            {
                enqueue(&queue, new_node(pop(&stack)->data, 1));
            }
            push(&stack, new_node(*p, 1));
        }
        else if (get_type(*p) == 2)
        {
            push(&stack, new_node(*p, 2));
        }
        else if (get_type(*p) == 3)
        {
            while (stack.top && stack.top->data != '(')
            {
                enqueue(&queue, new_node(pop(&stack)->data, 1));
            }
            pop(&stack);
        }
        p++;
    }
    while (stack.top)
    {
        enqueue(&queue, pop(&stack));
    }
    return queue;
}

int evaluate_postfix(QUEUE queue)
{
    // your code
    NODE *p = queue.front;
    STACK stack = {0};
    int type = 0;
    while (p)
    {
        type = p->type;
        if (type == 0)
        {
            push(&stack, new_node(p->data, 0));
        }
        else if (type == 1)
        {
            int operator= p->data;
            NODE *operand2 = pop(&stack);
            NODE *operand1 = pop(&stack);
            int result;
            switch (operator)
            {
            case '+':
                result = operand1->data + operand2->data;
                break;
            case '-':
                result = operand1->data - operand2->data;
                break;
            case '*':
                result = operand1->data * operand2->data;
                break;
            case '/':
                result = operand1->data / operand2->data;
                break;
            }
            push(&stack, new_node(result, 0));
            free(operand1);
            free(operand2);
        }
        p = p->next;
    }
    int result = stack.top->data;
    clean_stack(&stack);
    return result;
}

int evaluate_infix(char *infixstr)
{
    // your code
    QUEUE postfix_queue = infix_to_postfix(infixstr);
    int result = evaluate_postfix(postfix_queue);
    return result;
}