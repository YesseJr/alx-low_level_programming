#include <stdio.h>

/**
 *main - Printing the reversed alphabets, z-a by using Putcher
 *Return: Always 0 (Success)
 */

int main(void)
{
	char alpha = 'z';

	while (alpha >= 'a')
	{
		putchar(alpha);
		alpha--;
	}
	putchar('\n');

	return (0);
}