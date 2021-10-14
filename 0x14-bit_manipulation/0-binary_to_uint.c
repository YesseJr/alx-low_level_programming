/*
 * File: 0-binary_to_unit.c
 * Author: Waython Yesse
 * Year: 2021 October 14 (Nyerere Day!)
 */

#include "main.h"

int proc_binary(const char *b);

/**
 * proc_binary - Checks if the string contains only 0s and 1s.
 *
 * @b: const char pointer to string of binary numbers.
 *
 * Return: length of the string or -1 if b is null or contains a non  0 or 1
 * character.
 */

int proc_binary(const char *b)
{
	int length;

	length = -1;
	if (b)
	{
		length = 0;
		while (b[length])
		{
			if (b[length] == '1' || b[length] == '0')
				length++;
			else
				return (-1);
		}
	}
	return (length);
}
/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 *
 * @b: const char pointer to string of binary numbers.
 *
 * Return: The unsigned int represented by b.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	unsigned int bit;
	int length;

	/* may to need check if string b is longer than bits in an int */
	length = proc_binary(b);
	num  = 0;
	if (length != -1)
	{
		bit = 1;
		for (length--; length >= 0; length--)
		{
			num += bit * (b[length] - '0');
			bit = bit << 1;
		}
	}

	return (num);
}
