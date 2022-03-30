/* File: 103-exponential.c
 * Author: Waython Yesse
 */

#include "search_algos.h"

int binary_helper(int *array, int lo, int hi, int value);

/**
 * exponential_search - Performs exponential search on a sorted array of
 * integers.
 *
 * @array: Pointer to the sorted array of integers.
 * @size: The size of the array.
 * @value: The integer value to search for in the array.
 *
 * Return: The index at which `value` is found. -1 if array is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	int lo, hi;

	if (array == NULL || size < 1)
		return (-1);

	lo = 0;
	hi = 1;

	while (1)
	{
		if (hi < (int) size)
		{
			printf("Value checked array[%d] = [%d]\n", hi, array[hi]);
			lo = hi;
			hi *= 2;
		}
		else
		{
			hi = size - 1;
			break;
		}
		if (array[hi] >= value)
			break;
	}

	printf("Value found between indexes [%d] and [%d]\n", lo, hi);

	return (binary_helper(array, lo, hi, value));
}

/**
 * binary_helper - Performs binary search on the array.
 *
 * @array: Pointer to the sorted subarray of integers.
 * @lo: Lowest index of the subarray.
 * @hi: Highest index of the subarray.
 * @value: The value to search for in the array.
 *
 * Return: The index of where `value` is first found in the subarray. -1 if
 * `value` was not found.
 */
int binary_helper(int *array, int lo, int hi, int value)
{
	int i, m;

	while (lo <= hi)
	{
		printf("Searching in array: %d", array[lo]);
		for (i = lo + 1; i < hi + 1; i++)
			printf(", %d", array[i]);
		printf("\n");

		m = (hi - lo) / 2 + lo;
		if (value == array[m])
			return (m);

		if (value > array[m])
			lo = m + 1;
		else
			hi = m - 1;
	}

	return (-1);
}
