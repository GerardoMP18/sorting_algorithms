#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell sort algorithm
 * @array: list of numbers
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t salida;
	int tmp;
	size_t entrada;

	if (array == NULL)
	{
		return;
	}
	while (gap <= size / 3)
	{
		gap = (gap * 3) + 1;
	}

	while (gap > 0)
	{
		for (salida = gap; salida < size; salida++)
		{
			tmp = array[salida];
			entrada = salida;
			while (entrada > gap - 1 && array[entrada - gap] >= tmp)
			{
				array[entrada] = array[entrada - gap];
				entrada = entrada - gap;
			}
			array[entrada] = tmp;
		}
		gap = (gap - 1)/ 3;
		print_array(array, size);
	}
}
