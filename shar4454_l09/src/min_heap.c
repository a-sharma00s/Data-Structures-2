/**
 * -------------------------------------
 * @file  min_heap.c
 * Minimum Heap Source Code File
 * -------------------------------------
 * @author Ashish Sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version 2024-03-11
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

#define STRING_SIZE 80

// local functions

/**
 * Swaps two data values.
 *
 * @param a pointer to data.
 * @param b pointer to data.
 */
static void heap_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/**
 * Moves the last value in source until it is in its correct location
 * in source.
 *
 * @param source - pointer to a heap
 */
static void heapify_up(min_heap *source)
{

    // your code here
    int index = source->count - 1; // Start with the last element added
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (source->values[index] < source->values[parentIndex])
        {
            heap_swap(&source->values[index], &source->values[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

/**
 * Moves a value down source to its correct position.
 *
 * @param source - pointer to a heap
 */
static void heapify_down(min_heap *source)
{

    // your code here
    int index = 0;
    int leftChildIndex, rightChildIndex, smallerChildIndex;

    while (index < source->count)
    {
        leftChildIndex = 2 * index + 1;
        rightChildIndex = 2 * index + 2;
        smallerChildIndex = index;

        if (leftChildIndex < source->count && source->values[leftChildIndex] < source->values[smallerChildIndex])
        {
            smallerChildIndex = leftChildIndex;
        }

        if (rightChildIndex < source->count && source->values[rightChildIndex] < source->values[smallerChildIndex])
        {
            smallerChildIndex = rightChildIndex;
        }

        if (smallerChildIndex != index)
        {
            heap_swap(&source->values[index], &source->values[smallerChildIndex]);
            index = smallerChildIndex;
        }
        else
        {
            break;
        }
    }
}

// Public minimum heap functions

min_heap *min_heap_initialize(int capacity)
{
    min_heap *source = malloc(sizeof *source);
    source->values = malloc(capacity * sizeof *source->values);
    source->capacity = capacity;
    source->count = 0;
    return source;
}

void min_heap_free(min_heap **source)
{
    if (source != NULL && *source != NULL)
    {
        free((*source)->values);
        (*source)->values = NULL;
        free(*source);
        *source = NULL;
    }
    return;
}

void min_heap_heapify(min_heap *source, int *keys, int count)
{

    for (int i = 0; i < count; i++)
    {
        min_heap_insert(source, keys[i]);
    }
    return;
}

int min_heap_empty(const min_heap *source)
{
    return (source->count == 0);
}

int min_heap_full(const min_heap *source)
{
    return (source->count == source->capacity);
}

int min_heap_count(const min_heap *source)
{
    return (source->count);
}

void min_heap_insert(min_heap *source, const int value)
{
    // Add new value to end of the heap.
    source->values[source->count] = value;
    source->count++;
    // Fix the heap.
    heapify_up(source);
    return;
}

int min_heap_peek(const min_heap *source)
{
    return (source->values[0]);
}

int min_heap_remove(min_heap *source)
{
    int value = source->values[0];
    source->count--;

    if (source->count > 0)
    {
        // Move last value to top of heap.
        source->values[0] = source->values[source->count];
        // Fix the heap.
        heapify_down(source);
    }
    return value;
}

int min_heap_valid(const min_heap *source)
{

    // your code here
    for (int i = 0; i < source->count / 2; i++)
    {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if (leftChildIndex < source->count && source->values[i] > source->values[leftChildIndex])
        {
            return 0;
        }

        if (rightChildIndex < source->count && source->values[i] > source->values[rightChildIndex])
        {
            return 0;
        }
    }
    return 1;
}

int min_heap_replace(min_heap *source, int replacement)
{
    int value = source->values[0];
    source->values[0] = replacement;
    heapify_down(source);
    return value;
}

void heap_sort(int *values, int count)
{

    // your code here
    min_heap *heap = min_heap_initialize(count);
    min_heap_heapify(heap, values, count);

    for (int i = 0; i < count; i++)
    {
        values[i] = min_heap_remove(heap);
    }

    min_heap_free(&heap);
}

// for testing
void min_heap_print(const min_heap *source)
{
    printf("{");

    for (int i = 0; i < source->count; i++)
    {
        printf("%d, ", source->values[i]);
    }
    printf("}\n");
    return;
}
