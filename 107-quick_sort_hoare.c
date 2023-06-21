#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts a partition of the array using the Hoare partition scheme
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot = partition_hoare(array, low, high, size);
printf("Result [%d/%d]: ", high - low + 1, size);
print_array(array + low, high - low + 1);

quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * partition_hoare - Partitions the array using the Hoare partition scheme
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot element
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (true)
{
do
{
i++;
} while (array[i] < pivot);

do
{
j--;
} while (array[j] > pivot);

if (i >= j)
return j;

swap_elements(array, i, j);
}
}

/**
 * swap_elements - Swaps two elements in an array
 *
 * @array: The array containing the elements
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap_elements(int *array, int a, int b)
{
if (a != b)
{
int temp = array[a];
array[a] = array[b];
array[b] = temp;
printf("Swapped elements: %d <-> %d\n", array[a], array[b]);
}
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size)
{
for (size_t i = 0; i < size; i++)
{
if (i > 0)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}
