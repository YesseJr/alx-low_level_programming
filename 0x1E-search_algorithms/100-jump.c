/* File: 100-jump.c
 * Author: Waython Yesse
 */

#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Performs jump search on a sorted array of integers.
 *
 * @array: Pointer to the sorted array of integers.
 * @size: Size of the sorted array.
 * @value: Integer value for search for in the array.
 *
 * Return: The index at which `value` is found. -1 if the array is NULL or
 * `value` was not found.
 */
 
int jump_search(int *array, size_t size, int value)
{
	size_t sqr, lo, hi;

	if (array == NULL || size < 1)
		return (-1);

	lo = 0;
	sqr = sqrt(size);
	hi = sqr;

	while (1)
	{
		printf("Value checked array[%zd] = [%d]\n", lo, array[lo]);
		if (hi >= size || array[hi] >= value)
			break;
		lo = hi;
		hi += sqr;

	}

	printf("Value found between indexes [%zd] and [%zd]\n", lo, hi);

	for (; lo < hi + 1 && lo < size; lo++)
	{
		printf("Value checked array[%zd] = [%d]\n", lo, array[lo]);
		if (array[lo] == value)
			return (lo);
	}

	return (-1);
}
