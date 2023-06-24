#include "sort.h"

void swap(int *a, int *b);
int partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);


/**
 * swap - Swaps two elements in an array
 *
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * partition - Performs the partition step in Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
int pivot = array[high];
int i = (low - 1);
int j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, high + 1);
}
}

swap(&array[i + 1], &array[high]);
print_array(array, high + 1);

return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
if (low < high)
{
int pivot = partition(array, low, high);
quick_sort_recursive(array, low, pivot - 1);
quick_sort_recursive(array, pivot + 1, high);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1);
}
