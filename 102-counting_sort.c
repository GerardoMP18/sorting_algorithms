#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: list of elements
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	size_t max, x, data;
	int *count_array, *salida;

	if (array == NULL || size < 2)
		return;

	max = maximo(array, size);
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;
	salida = malloc(sizeof(int) * size);
	if (salida == NULL)
		return;
	for (x = 0; x <= max; x++)
	{
		count_array[x] = 0;
	}
	for (x = 0; x < size; x++)
	{
		data  = array[x];
		count_array[data] = count_array[data] + 1;
	}
	for (x = 1; x <= max; x++)
	{
		count_array[x] = count_array[x] + count_array[x - 1];
	}
	print_array(count_array, max + 1);

	for (x = 0; x < size; x++)
	{
		data = count_array[array[x]];
		salida[data - 1] = array[x];
		count_array[array[x]]--;
	}
	for (x = 0; x < size; x++)
	{
		array[x] = salida[x];
	}
	free(salida);
	free(count_array);
}

/**
 * maximo - Function to get the largest number in the array
 * @array: list of elements
 * @size: size of array;
 * Return: maximun number
 */
int maximo(int *array, size_t size)
{
	size_t x;
	int maximo = array[0];

	for (x = 1; x < size; x++)
	{
		if (array[x] > maximo)
		{
			maximo = array[x];
		}
	}
	return (maximo);
}
