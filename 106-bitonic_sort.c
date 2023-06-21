#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

bitonic_sort_recursive(array, size, 0, size, true);
}

/**
 * bitonic_sort_recursive - Recursively sorts a section of the array in a bitonic sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @start: Starting index of the section
 * @count: Number of elements in the section
 * @asc: Flag indicating the sorting order (true for ascending, false for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, bool asc)
{
if (count > 1)
{
size_t mid = count / 2;

bitonic_sort_recursive(array, size, start, mid, true);
bitonic_sort_recursive(array, size, start + mid, mid, false);

bitonic_merge(array, size, start, count, asc);
printf("Result [%lu/%lu] (UP=%d): ", count, size, asc);
print_array(array + start, count);
}
}

/**
 * bitonic_merge - Merges two sub-arrays in a bitonic sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @start: Starting index of the first sub-array
 * @count: Number of elements in the merged sub-arrays
 * @asc: Flag indicating the sorting order (true for ascending, false for descending)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t count, bool asc)
{
if (count > 1)
{
size_t step = count / 2;

for (size_t i = start; i < start + step; i++)
compare_swap(array, size, i, i + step, asc);

bitonic_merge(array, size, start, step, asc);
bitonic_merge(array, size, start + step, step, asc);
}
}

/**
 * compare_swap - Compares and swaps two elements based on the sorting order
 *
 * @array: The array containing the elements
 * @size: Number of elements in the array
 * @a: Index of the first element
 * @b: Index of the second element
 * @asc: Flag indicating the sorting order (true for ascending, false for descending)
 */
void compare_swap(int *array, size_t size, size_t a, size_t b, bool asc)
{
if ((array[a] > array[b] && asc) || (array[a] < array[b] && !asc))
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
