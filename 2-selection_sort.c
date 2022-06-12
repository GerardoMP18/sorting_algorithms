#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: list
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t minimo;
	size_t x;
	size_t z;
	size_t temp;

	if ((array != NULL) && (size >= 2))
	{
		for (x = 0; x < size; x++)
		{
			minimo = x;
			for (z = x + 1; z < size; z++)
			{
				if (array[z] < array[minimo])
				{
					minimo = z;
				}
			}
			if (minimo != x)
			{
				temp = array[x];
				array[x] = array[minimo];
				array[minimo] = temp;
				print_array(array, size);
			}
		}
	}
}
