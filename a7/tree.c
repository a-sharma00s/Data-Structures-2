/*
   file name: tree.c
 * Ashish Sharma, 169044454, shar4454@mylaurier.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root)
{
    // your code
    TPROPS tree_props = {0};

    if (root == NULL)
    {
        return tree_props;
    }

    tree_props.order = 1 + tree_property(root->left).order + tree_property(root->right).order;
    int left_height = 1 + tree_property(root->left).height;
    int right_height = 1 + tree_property(root->right).height;
    tree_props.height = (left_height > right_height) ? left_height : right_height;

    return tree_props;
}

void preorder(TNODE *root)
{
    // your code
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TNODE *root)
{
    // your code
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(TNODE *root)
{
    // your code
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void bforder(TNODE *root)
{
    // your code
    if (root == NULL)
    {
        return;
    }

    QUEUE new_queue = {0};
    enqueue(&new_queue, root);

    while (new_queue.front)
    {
        TNODE *current = (TNODE *)dequeue(&new_queue);
        printf("%c ", current->data);

        if (current->left != NULL)
            enqueue(&new_queue, current->left);

        if (current->right != NULL)
            enqueue(&new_queue, current->right);
    }

    clean_queue(&new_queue);

    return;
}

TNODE *bfs(TNODE *root, char val)
{
    // your code
    TNODE *result_node = NULL;

    if (root)
    {
        QUEUE new_queue = {0};
        enqueue(&new_queue, root);

        while (new_queue.front)
        {
            TNODE *tnp = (TNODE *)dequeue(&new_queue);
            if (tnp->data == val)
            {
                result_node = tnp;
                break;
            }

            if (tnp->left != NULL)
                enqueue(&new_queue, tnp->left);

            if (tnp->right != NULL)
                enqueue(&new_queue, tnp->right);
        }

        clean_queue(&new_queue);
    }
    return result_node;
}

TNODE *dfs(TNODE *root, char val)
{
    // your code
    TNODE *result_node = NULL;

    if (root)
    {
        STACK new_stack = {0};
        push(&new_stack, root);

        while (new_stack.top)
        {
            TNODE *tnp = (TNODE *)pop(&new_stack);
            if (tnp->data == val)
            {
                result_node = tnp;
                break;
            }

            if (tnp->right != NULL)
                push(&new_stack, tnp->right);

            if (tnp->left != NULL)
                push(&new_stack, tnp->left);
        }

        clean_stack(&new_stack);
    }
    return result_node;
}

// the following functions are given, need to add to your program.

TNODE *new_node(char val)
{
    TNODE *np = (TNODE *)malloc(sizeof(TNODE));
    if (np != NULL)
    {
        np->data = val;
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

void clean_tree(TNODE **rootp)
{
    TNODE *p = *rootp;
    if (p)
    {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

void insert_tree(TNODE **rootp, char val)
{
    if (*rootp == NULL)
    {
        *rootp = new_node(val);
    }
    else
    {
        QUEUE queue = {0};
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front)
        {
            p = dequeue(&queue);
            if (p->left == NULL)
            {
                p->left = new_node(val);
                break;
            }
            else
            {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL)
            {
                p->right = new_node(val);
                break;
            }
            else
            {
                enqueue(&queue, p->right);
            }
        }
    }
}