/*
 * File: 4-print_alphabt.c
 * Author: Waython Yesse
 * Occupation: Software Engineering at ALX
 */

#include <stdio.h>

/**
 *main - print lowercase alpha a-z but remove 'q' and 'e'
 *Return: Always 0 (Success)
 */

int main(void)
{
	char love = 'a';

	while (love <= 'z')
	{
		if ((love != 'q') && (love != 'e'))
		{
			putchar(love);
		}
		love++;
	}
	putchar('\n');

	return (0);
}
