/* File: 103-exponential.c
 * Author: Waython Yesse
 */

#include "search_algos.h"

/**
 * exponential_search - search by half
 * @array: The sort array
 * @size: Size of the array
 * @value: Value to search into the array
 * Return: The index of the value or -1 if it fails
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1;
	int max;

	if (size == 0 || array == NULL)
		return (-1);

	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	if (((int)size - 1) < bound)
		max = size - 1;
	else
		max = bound;

	printf("Value found between indexes [%d] and [%d]\n", bound / 2, max);

	return (binary_search_new(array, bound / 2, max, value));
}
