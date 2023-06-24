#include "sort.h"

/**
 * max_int - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_int(int *array, int size)
{
int max_int, k;

for (max_int = array[0], k = 1; k < size; k++)
{
if (array[k] > max_int)
max_int = array[k];
}

return (max_int);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
int *count, *sorted, max_int, k;

if (array == NULL || size < 2)
return;

sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
max_int = max_int(array, size);
count = malloc(sizeof(int) * (max_int + 1));
if (count == NULL)
{
free(sorted);
return;
}

for (k = 0; k < (max_int + 1); k++)
count[k] = 0;
for (k = 0; k < (int)size; k++)
count[array[k]] += 1;
for (k = 0; k < (max_int + 1); k++)
count[k] += count[k - 1];
print_array(count, max_int + 1);

for (k = 0; k < (int)size; k++)
{
sorted[count[array[k]] - 1] = array[k];
count[array[k]] -= 1;
}

for (k = 0; k < (int)size; k++)
array[k] = sorted[k];

free(sorted);
free(count);
}
