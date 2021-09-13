#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

scanf("%d %d %d", &a,&b,&c); //taking three numbers as input

	if (a >= b && a >= c)
	{
	printf("largest number:%d, largest = a);
	}
	else if (b >= a && b >= c)
	{
	printf("largest number:%d, largest = b);
	}
	else
	{
	printf(largest number:%d, largest = c);
	}

	return (largest);
}
