#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
int max, i;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
int *count, *sorted, max, i;

if (array == NULL || size < 2)
return;

sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;

max = get_max(array, size);
count = calloc(max + 1, sizeof(int));
if (count == NULL)
{
free(sorted);
return;
}

for (i = 0; i < (int)size; i++)
count[array[i]]++;

for (i = 1; i <= max; i++)
count[i] += count[i - 1];

for (i = (int)size - 1; i >= 0; i--)
{
sorted[count[array[i]] - 1] = array[i];
count[array[i]]--;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted[i];

print_array(count, max + 1);

free(sorted);
free(count);
}
