/*
 * File: 0-linear.c
 * Author: Waython Yesse
 */

#include "search_algos.h"

/**
 * binary_search - Performs binary search on an array of sorted integers.
 *
 * @array: Pointer to the sorted array of integers.
 * @size: The size of the array.
 * @value: The value to search for in the array.
 *
 * Return: The index of where `value` is first found in the array. -1 if the
 * array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lo, hi, mi, i;

	if (array == NULL || size < 1)
		return (-1);

	lo = 0;
	hi = size - 1;
	while (lo <= hi)
	{
		printf("Searching in array: %d", array[lo]);
		for (i = lo + 1; i < hi + 1; i++)
			printf(", %d", array[i]);
		printf("\n");

		mi = (hi - lo) / 2 + lo;
		if (value == array[mi])
			return (mi);

		if (value > array[mi])
			lo = mi + 1;
		else
			hi = mi - 1;
	}

	return (-1);
}
