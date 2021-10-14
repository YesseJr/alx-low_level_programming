#include "lists.h"

/**
 * free_listint_safe - Frees a list_t list. Not the safest version, however it
 * is compliant with the task's requirement of 'go through the list only once'.
 * The function will not work properly if the heap does not grow downwards (
 * architecture wise or reusing memory from above). It would not be possible to
 * achieve the same result by going through the list only once without usage of
 * a visited record.
 * @h: Pointer to a pointer to the beginning of the list.
 *
 * Return: Size of the freed list.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *next;
	size_t count;

	count = 0;
	if (!h)
		return (count);
	while (*h)
	{
		count++;
		next = (*h)->next;
		free((*h));
		if (next && ((void *) next) < (void *) (*h))
			*h = next;
		else
			break;
	}
	*h = NULL;
	return (count);
}
