#include "sort.h"

void _hoaresort(int *array, size_t size, int left, int right);
int _hoarepart(int *array, size_t size, int left, int right);
void _swapfunc(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);

/**
 * _swapfunc - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void _swapfunc(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * _hoarepart - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int _hoarepart(int *array, size_t size, int left, int right)
{
int pivot, above, below;
pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
_swapfunc(array + above, array + below);
print_array(array, size);
}
}
return (above);
}

/**
 * _hoaresort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void _hoaresort(int *array, size_t size, int left, int right)
{
int part;
if (right - left > 0)
{
part = _hoarepart(array, size, left, right);
_hoaresort(array, size, left, part - 1);
_hoaresort(array, size, part, right);
}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

_hoaresort(array, size, 0, size - 1);
}
