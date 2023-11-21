#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - Selection sort implementation
 * @array: array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int hold;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			hold = array[min];
			array[min] = array[i];
			array[i] = hold;
			print_array(array, size);
		}
	}
}
