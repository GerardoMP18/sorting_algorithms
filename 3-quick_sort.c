#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if ((array != NULL) && (size >= 2))
	{
		quicksort(array, 0, size - 1, size);
	}
}

/**
 * quicksort -  Recursion function to index the partition
 * @array: array of the partition
 * @low: left block
 * @high: right left
 * @size: size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * partition - function to partition the array
 * @array: array of partition
 * @low: left block
 * @high: right block
 * @size: size of array
 * Return:partition of array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot_part;
	int temp;
	int i, j;

	pivot_part = array[high];

	j = low - 1;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot_part)
		{
			j++;
			if (j != i)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	j++;
	if (j != i)
	{
		temp = array[j];
		array[j] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (j);
}

