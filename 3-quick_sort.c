#include <stdlib.h>
#include "sort.h"
/**
 * pivot_sort - quick sort and return pivot
 * @array: array to sort
 * @start: start of array
 * @end: end of array
 * @size: size of array
 * Return: new pivot
 */
int pivot_sort(int *array, int start, int end, size_t size)
{
	int j, hold;
	int i = start - 1;
	int swapped = 0;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			hold = array[i];
			array[i] = array[j];
			array[j] = hold;
			print_array(array, size);
			swapped = 1;
		}
	}
	hold = array[i + 1];
	array[i + 1] = array[end];
	array[end] = hold;
	return (i + 1);
}
/**
 * mysort - takes pivot and calls pivot function
 * @array: array to sort
 * @start: start
 * @end: end
 * @size: size of array
 */
void mysort(int *array, int start, int end, int size)
{
	int p;

	if (start >= end)
		return;

	p = pivot_sort(array, start, end, size);

	mysort(array, p + 1, end, size);
	mysort(array, start, p - 1, size);
}

/**
 * quick_sort - quick sort implementation
 * @array: Array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	mysort(array, 0, size - 1, size);
}
