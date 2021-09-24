#include "main.h"
#include <stdlib.h>

/**
  * string_nconcat - concatenates two strings
  * @s1: first string to copy
  * @s2: second string to copy
  * @n: number of bytes of s2 to copy
  *
  * Return: pointer to new char
  */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;

	unsigned int i, j, len = n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		;

	for (j = 0; s2[j]; j++)
		;

	if (j > n)
		j = n;

	str = malloc(sizeof(char) * (i + j + 1));

	if (str == NULL)
		return (NULL);

	for (len = 0; len < i; len++)
	{
		str[len] = s1[len];
	}

	for (len = 0; len < j; len++)
	{
		str[len + i] = s2[len];
	}

	str[i + j] = '\0';

	return (str);
}
