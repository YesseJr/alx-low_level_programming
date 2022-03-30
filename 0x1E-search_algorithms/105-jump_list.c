#include "search_algos.h"

/**
 * jump_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using jump search.
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, i, lo_i, hi_i;
	listint_t *lo, *hi;

	if (list == NULL || size < 1)
		return (NULL);

	step = sqrt(size);
	lo = list;
	hi = list;
	for (i = 0; i < step; i++)
		hi = hi->next;
	lo_i = 0;
	hi_i = step;

	while (1)
	{
		printf("Value checked at index [%zd] = [%d]\n", hi_i, hi->n);
		if (hi->n >= value || hi_i == size - 1)
			break;
		lo = hi;
		for (i = 0; i < step && hi->next != NULL; i++)
			hi = hi->next;
		lo_i = hi_i;
		hi_i += step;
		if (hi_i >= size)
			hi_i = size - 1;
	}

	printf("Value found between indexes [%zd] and [%zd]\n", lo_i, hi_i);

	for (; lo_i < hi_i + 1 && lo_i < size; lo_i++, lo = lo->next)
	{
		printf("Value checked at index [%zd] = [%d]\n", lo_i, lo->n);
		if (lo->n == value)
			return (lo);
	}

	return (NULL);
}
