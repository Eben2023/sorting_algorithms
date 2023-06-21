#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Find the maximum element to determine the number of digits */
int max = find_max(array, size);

/* Perform LSD Radix Sort for each digit */
for (unsigned int exp = 1; max / exp > 0; exp *= 10)
{
counting_sort(array, size, exp);
print_array(array, size);
}
}

/**
 * find_max - Finds the maximum element in an array
 *
 * @array: The array to be searched
 * @size: Number of elements in the array
 *
 * Return: The maximum element
 */
int find_max(int *array, size_t size)
{
int max = INT_MIN;

for (size_t i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return max;
}

/**
 * counting_sort - Performs Counting Sort based on a significant digit
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current significant digit
 */
void counting_sort(int *array, size_t size, unsigned int exp)
{
int *output = malloc(size * sizeof(int));
int count[10] = {0};

if (output == NULL)
return;

/* Count the occurrences of each digit */
for (size_t i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

/* Calculate the cumulative count */
for (int i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Build the output array */
for (int i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

/* Copy the sorted elements back to the original array */
for (size_t i = 0; i < size; i++)
array[i] = output[i];

free(output);
}
