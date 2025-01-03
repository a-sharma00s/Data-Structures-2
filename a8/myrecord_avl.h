/*
 * -----------------------------------------------------
 @file myrecord_avl.h
 -------------------------------------------------------
 @author Ashish Sharma, shar4454@mylaurier.ca, 169044454
 @version 2024-03-16
 -------------------------------------------------------
 */

/*  This structure holds the root pointer of AVL tree data structure,
 *  and count, mean and stddev of the data.score in the AVL tree.
 */
#ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H
typedef struct
{
    AVLNODE *root;
    int count;
    float mean;
    float stddev;
} AVLDS;

typedef struct
{
    AVLNODE *root;
    int count;
    float mean;
    float stddev;
} AVLDS;

void merge_avl(AVLNODE **dest_rootp, AVLNODE **source_rootp);

void merge_avlds(AVLDS *dest, AVLDS *source);

void clean_avlds(AVLDS *ds);

void add_record(AVLDS *ds, RECORD data);

void remove_record(AVLDS *ds, char *name);

#endif