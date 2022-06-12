#include "sort.h"

/**
 * bubble_sort - Function that sort an array of integers in asceding
 * order using the Bubble sort algorithm
 * @array: list of numbers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x;
	size_t y;
	size_t tmp;

	if ((array != NULL) && (size >= 2))
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < (size - 1); y++)
			{
				if (array[y] > array[y + 1])
				{
					tmp = array[y];
					array[y] = array[y + 1];
					array[y + 1] = tmp;
					print_array(array, size);
				}
			}
		}
	}
}
