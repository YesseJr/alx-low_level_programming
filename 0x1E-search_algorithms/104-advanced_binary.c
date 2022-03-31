#include "search_algos.h"

int binary_helper(int *array, int lo, int hi, int value);

/**
 * advanced_binary - Performs binary search on a sorted array of integers.
 * Returns the index of the first occurence of `value` inside the array.
 *
 * @array: Pointer to the sorted integer array.
 * @size: The size of the array.
 * @value: The integer value to search for in the array.
 *
 * Return: The index of the first occurence of `value` in the array. -1 if
 * `value` was not found or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size < 1)
		return (-1);

	return (binary_helper(array, 0, size - 1, value));
}

/**
 * binary_helper - A recursive function to handle binary search.
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

	if (lo > hi)
		return (-1);

	printf("Searching in array: %d", array[lo]);
	for (i = lo + 1; i < hi + 1; i++)
		printf(", %d", array[i]);
	printf("\n");

	if (array[lo] == value)
		return (lo);

	m = (hi - lo) / 2 + lo;

	if (value > array[m])
		return (binary_helper(array, m + 1, hi, value));
	else
		return (binary_helper(array, lo, m, value));
}
