/*
 * -----------------------------------------------------
 @file myrecord_avl.c
 -------------------------------------------------------
 @author Ashish Sharma, shar4454@mylaurier.ca, 169044454
 @version 2024-03-16
 -------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "myrecord_avl.h"

static void calculate_stats_recursive(AVLNODE *root, int *count, float *sum, float *sum_sq_diff) {
    if (root == NULL) {
        return;
    }
    calculate_stats_recursive(root->left, count, sum, sum_sq_diff);
    *sum += root->data.score;
    *sum_sq_diff += (root->data.score * root->data.score);
    (*count)++;
    calculate_stats_recursive(root->right, count, sum, sum_sq_diff);
}

static void calculate_stats(AVLDS *ds) {
    if (ds->root == NULL) {
        ds->count = 0;
        ds->mean = 0;
        ds->stddev = 0;
        return;
    }

    float sum = 0;
    float sum_sq_diff = 0;
    int count = 0;

    calculate_stats_recursive(ds->root, &count, &sum, &sum_sq_diff);

    ds->count = count;
    ds->mean = sum / count;
    ds->stddev = sqrt((sum_sq_diff / count) - (ds->mean * ds->mean));
}

void merge_avl(AVLNODE **rootp_dest, AVLNODE **rootp_source)
{
    // your code
    if (*rootp_source == NULL) {
        return;
    }
    avl_insert(rootp_dest, (*rootp_source)->data);
    merge_avl(rootp_dest, &(*rootp_source)->left);
    merge_avl(rootp_dest, &(*rootp_source)->right);
}

void merge_avlds(AVLDS *dest, AVLDS *source)
{
    // your code
    merge_avl(&dest->root, &source->root);
    dest->count += source->count;
    calculate_stats(dest);
    clean_avlds(source);
}

void clean_avlds(AVLDS *ds)
{
    clean_avl(&ds->root);
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}

// the following functions are adapted from a7q3
void add_record(AVLDS *tree, RECORD data)
{
    if (avl_search(tree->root, data.name) == NULL)
    {
        avl_insert(&(tree->root), data);
        int count = tree->count;
        float mean = tree->mean;
        float stddev = tree->stddev;
        tree->count = count + 1;
        tree->mean = (mean * count + data.score) / (count + 1.0);
        tree->stddev = sqrt(data.score * data.score / (count + 1.0) + (stddev * stddev + mean * mean) * (count / (count + 1.0)) - tree->mean * tree->mean);
    }
    else
    {
        printf("record exits");
    }
}

void remove_record(AVLDS *tree, char *name)
{
    AVLNODE *np = NULL;
    if ((np = avl_search(tree->root, name)) != NULL)
    {
        float score = np->data.score;
        avl_delete(&(tree->root), name);
        float count = tree->count;
        float mean = tree->mean;
        float stddev = tree->stddev;
        tree->count = count - 1;
        if (count >= 3)
        {
            tree->mean = (mean * count - score) / (count - 1.0);
            tree->stddev = sqrt((stddev * stddev + mean * mean) * (count / (count - 1.0)) - score * score / (count - 1.0) - tree->mean * tree->mean);
        }
        else if (count == 2)
        {
            tree->mean = mean * count - score;
            tree->stddev = 0;
        }
        else
        {
            tree->mean = 0;
            tree->stddev = 0;
        }
    }
    else
    {
        printf("record does not exit");
    }
}