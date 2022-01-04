/*
 * File: 3-print_alphabet.c
 * Author: Waython Yesse
 * Occupation: Software Engineering Student at ALX
 */

#include <stdio.h>

/**
 *main - print lowercase and uppercase a-z, A-Z by using putchar
 *Return: Always 0 (Success)
 */

int main(void)
{
	char side_A = 'a';
	char side_B = 'A';

	while (side_A <= 'z')
	{
		putchar(side_A);
		side_A++;
	}

	while (side_B <= 'Z')
	{
		putchar(side_B);
		side_B++;
	}

	putchar('\n');

	return (0);
}
