/*
 * File: 2-print_alphabet.c
 * Author: Waython Yesse
 * Occupation: Software Engineering Student at ALx 
*/
#include <stdio.h>

/**
 *main - print lowercase a-z
 *Return: Always 0 (Success)
 */

int main(void)
{
	char Waython = 'a';

	while (Waython <= 'z')
	{
		putchar(Waython);
		Waython++;
	}
	putchar('\n');

	return (0);
}
