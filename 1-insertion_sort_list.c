#include "sort.h"

/**
 * insertion_sort_list -  Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list of array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	int i;

	tmp = *list;

	if (tmp != NULL)
		return;

	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			i = tmp->n;
			*(int *)&tmp->n = tmp->next->n;
			*(int *)&tmp->next->n = i;
			print_list(*list);

			while (tmp->prev != NULL)
			{
				if (tmp->prev->n > tmp->n)
				{
					i = tmp->prev->n;
					*(int *)&tmp->prev->n = tmp->n;
					*(int *)&tmp->n = i;
					print_list(*list);
				}
				else
					break;
				tmp = tmp->prev;
			}
		}
		tmp = tmp->next;
	}
}
