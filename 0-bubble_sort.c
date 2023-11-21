#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - a bubble sort implementation
 * @array: an array
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, sorted;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		sorted = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = 1;
				print_array(array, size);
			}
		}
		if (sorted == 0)
			break;
	}
}
