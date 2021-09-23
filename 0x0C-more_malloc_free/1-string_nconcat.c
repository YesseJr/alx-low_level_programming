#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: max no of bytes of s2 to concatenate to s1
 * Return: if concatenation fails - NULL
 * Otherwise, a pointer to the concatenated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	int x;
	unsigned int y;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	x = 0;

	while (s1[x] != '\0')
		x++;

	str = malloc(sizeof(char) * (x + n + 1));

	if (str == NULL)
		return (NULL);

	x = y = 0;

	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (y < n && s2[y] != '\0')
	{
		str[x] = s2[y];
		x++, y++;
	}

	str[x] = '\0';
	return (str);
}
