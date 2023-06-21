#include <stdio.h>
#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Build the heap (rearrange the array) */
build_heap(array, size);

/* Heap sort */
for (int i = size - 1; i > 0; i--)
{
/* Swap the root (largest element) with the last element */
swap(&array[0], &array[i]);
print_array(array, size);

/* Sift down the new root to maintain the heap property */
sift_down(array, i, 0);
}
}

/**
 * build_heap - Builds a heap from an array
 *
 * @array: The array to be transformed into a heap
 * @size: Number of elements in the array
 */
void build_heap(int *array, size_t size)
{
/* Start from the last non-leaf node and sift down each node */
for (int i = size / 2 - 1; i >= 0; i--)
sift_down(array, size, i);
}

/**
 * sift_down - Sifts down a node in the heap to maintain the heap property
 *
 * @array: The array representing the heap
 * @size: Number of elements in the array
 * @index: Index of the node to be sifted down
 */
void sift_down(int *array, size_t size, int index)
{
int largest = index;
int left = 2 * index + 1;
int right = 2 * index + 2;

/* Compare the left child with the current root */
if (left < size && array[left] > array[largest])
largest = left;

/* Compare the right child with the current root */
if (right < size && array[right] > array[largest])
largest = right;

/* If the largest is not the current root, swap and sift down the new root */
if (largest != index)
{
swap(&array[index], &array[largest]);
print_array(array, size);
sift_down(array, size, largest);
}
}

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
