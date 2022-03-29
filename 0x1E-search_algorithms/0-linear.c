#include "search_algos.h"

/**
 * linear_search - search linearly
 * @array: is a pointer to the first element
 * @size: number of elements in array
 * @value: value to search for
 * Return: -1 if array is not present or NULL
 */
 
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; (i < size) && (array); i++)
	{
		if (*(array + i) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)i, *(array + i));
			return (i);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)i, *(array + i));
		}
	}
	return (-1);
}
