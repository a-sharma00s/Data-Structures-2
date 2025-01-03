/*
 * myrecord_bst.c
 Ashish Sharma, 169044454, shar4454@mylaurier.ca
 */

#include <stdio.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_record(BSTDS *tree, RECORD record)
{
    // your code
    bst_insert(&(tree->root), record);
    tree->count++;
    float x = tree->mean;
    tree->mean = x + (record.score - x) / tree->count;

    if (tree->count == 1)
    {
        tree->stddev = 0;
    }
    else
    {
        float delta = record.score - x;
        float delta_x = delta * (record.score - tree->mean);
        tree->stddev = sqrt(((tree->count - 1) * tree->stddev * tree->stddev + delta_x) / tree->count);
    }
}

void remove_record(BSTDS *ds, char *name)
{
    // your code
    BSTNODE **initPtr, *curr;

    float prev_mean, score_diff, sq_score_diff;

    initPtr = &ds->root;
    while (*initPtr != NULL) {
        int cmp = strcmp(name, (*initPtr)->data.name);
        if (cmp == 0) {
            curr = *initPtr;
            break;
        } else if (cmp < 0) {
            initPtr = &((*initPtr)->left);
        } else {
            initPtr = &((*initPtr)->right);
        }
    }

    if (*initPtr == NULL) {
        printf("Node with name %s not found\n", name);
        return;
    }

    prev_mean = ds->mean;
    score_diff = curr->data.score - prev_mean;
    ds->count--;

    if (ds->count == 0) {
        ds->mean = 0;
        ds->stddev = 0;
    } else {
        ds->mean = prev_mean - (score_diff / ds->count);
        sq_score_diff = score_diff * (curr->data.score - ds->mean);

        if (ds->count == 1) {
            ds->stddev = 0;
        } else {
            ds->stddev = sqrt(((ds->count + 1) * (ds->stddev * ds->stddev) - sq_score_diff) / ds->count);
        }
    }
    bst_delete(initPtr, name);
}

void clean_bstds(BSTDS *ds)
{
    clean_bst(&ds->root);
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}