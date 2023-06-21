#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Allocate a temporary array for merging */
int *temp_array = malloc(size * sizeof(int));
if (temp_array == NULL)
return;

merge_sort_recursive(array, 0, size - 1, temp_array);
free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function for Merge Sort
 *
 * @array: The array to be sorted
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @temp_array: Temporary array for merging
 */
void merge_sort_recursive(int *array, int left, int right, int *temp_array)
{
if (left < right)
{
int middle = left + (right - left) / 2;

merge_sort_recursive(array, left, middle, temp_array);
merge_sort_recursive(array, middle + 1, right, temp_array);

merge_arrays(array, left, middle, right, temp_array);
}
}

/**
 * merge_arrays - Merges two subarrays in ascending order
 *
 * @array: The array to be sorted
 * @left: Left index of the first subarray
 * @middle: Right index of the first subarray
 * @right: Right index of the second subarray
 * @temp_array: Temporary array for merging
 */
void merge_arrays(int *array, int left, int middle, int right, int *temp_array)
{
int i = left;
int j = middle + 1;
int k = left;

printf("Merging subarrays: ");
print_array(array + left, right - left + 1);

/* Merge elements from the subarrays into the temporary array */
while (i <= middle && j <= right)
{
if (array[i] <= array[j])
{
temp_array[k] = array[i];
i++;
}
else
{
temp_array[k] = array[j];
j++;
}
k++;
}

/* Copy the remaining elements from the left subarray */
while (i <= middle)
{
temp_array[k] = array[i];
i++;
k++;
}

/* Copy the remaining elements from the right subarray */
while (j <= right)
{
temp_array[k] = array[j];
j++;
k++;
}

/* Copy the merged elements back to the original array */
for (i = left; i <= right; i++)
array[i] = temp_array[i];

printf("Result: ");
print_array(array + left, right - left + 1);
}
