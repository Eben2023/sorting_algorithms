#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
int max_value = 0;
size_t i;
int *counting_array, *sorted_array;

if (array == NULL || size < 2)
return;

/* Find the maximum value in the array */
for (i = 0; i < size; i++)
{
if (array[i] > max_value)
max_value = array[i];
}

/* Create the counting array with size max_value + 1 */
counting_array = malloc((max_value + 1) * sizeof(int));
if (counting_array == NULL)
return;

/* Initialize the counting array with zeros */
for (i = 0; i <= max_value; i++)
counting_array[i] = 0;

/* Count the occurrences of each element in the array */
for (i = 0; i < size; i++)
counting_array[array[i]]++;

printf("Counting array: ");
print_array(counting_array, max_value + 1);

/* Compute the cumulative sum of the counting array */
for (i = 1; i <= max_value; i++)
counting_array[i] += counting_array[i - 1];

/* Create a sorted array */
sorted_array = malloc(size * sizeof(int));
if (sorted_array == NULL)
{
free(counting_array);
return;
}

/* Place elements in the sorted array based on counting array */
for (i = 0; i < size; i++)
{
sorted_array[counting_array[array[i]] - 1] = array[i];
counting_array[array[i]]--;
}

/* Copy the sorted array back to the original array */
for (i = 0; i < size; i++)
array[i] = sorted_array[i];

printf("Sorted array: ");
print_array(array, size);

free(counting_array);
free(sorted_array);
}
