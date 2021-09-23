#include <stdlib.h>
#include <stdio.h>

unsigned int num_len(char *s);

void *_calloc0(unsigned int nmemb, unsigned int size);

void _mul(char *total, char *num1, unsigned int len1, char digit2);

/**
 * num_len - Returns the length of a string containing numbers. If there's a
 * non digit, prints Error and exits with status 98.
 *
 * @s: A pointer to the character string.
 *
 * Return: The length of the character string.
 */

unsigned int num_len(char *s)
{
	unsigned int length;

	length = 0;

	while (s[length])
	{
		if (s[length] < '0' || s[length] > '9')
		{
			printf("Error\n");
			exit(98);
		}
		length++;
	}
	return (length);
}

/**
  * _calloc0 - Allocates memory for an array using malloc and then sets the
  * memory to character 0.
  * @nmemb: Number of elements to allocate for the array.
  * @size: Size in bytes of each element.
  *
  * Return: A void pointer to the first byte of the allocated memory, or NULL.
  */

void *_calloc0(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;
	unsigned int bytes;

	bytes = nmemb * size;

	if (bytes <= 0)
		return (NULL);

	ptr = malloc(bytes);

	if (!ptr)
		return (NULL);

	for (i = 0; i < bytes; i++)
		ptr[i] = '0';

	return ((void *) ptr);
}

/**
  * _mul - Iterate through the first number and multiply each digit with the
  * digit from the second number, then add to total so far.
  * @total: Pointer to the product of the first number and the second number.
  * Points specifically to the last byte in memory that will be changed at the
  * beginning of the function call. During the first function call the pointer
  * points to the second to last byte in memory (last being the null byte).
  * Each subsequent time the function is called, the pointer starts 1
  * byte further to the left than the previous call. The pointer moves left
  * with each loop during the function execution.
  * @num1: Pointer to char string containing the first number.
  * @len1: Length of the first number.
  * @digit2: Current digit from the second number.
  *
  * Return: void.
  */

void _mul(char *total, char *num1, unsigned int len1, char digit2)
{
	int j;
	unsigned int sum;
	unsigned int leftover;

	leftover = 0;

	for (j = len1 - 1; j >= 0; j--)
	{
		sum = (num1[j] - '0') * (digit2 - '0') + (*total - '0') + leftover;
		leftover = sum / 10;
		*total = (sum % 10) + '0';
		total--;
	}
	*total = leftover + '0';
}

/**
  * main - Multiplies two positive numbers and prints to terminal.
  * @argc: The number of arguments passed.
  * @argv: A pointer to an array of pointers that point to the arguments.
  *
  * Return: 0 upon successful run.
  */

int main(int argc, char **argv)
{
	char *total;
	char *num1;
	char *num2;
	int i;
	unsigned int len1;
	unsigned int len2;
	unsigned int shift_left;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	len1 = num_len(argv[1]);
	len2 = num_len(argv[2]);
	num1 = argv[1];
	num2 = argv[2];

	total = _calloc0(len2 + len1 + 1, sizeof(*total));

	if (!total)
	{
		printf("Allocation of total has failed\n");
		exit(98);
	}

	shift_left = 0;
	/* iterate through each digit in num2 starting with last*/
	for (i = len2 - 1; i >= 0; i--)
	{
		/* pass address of the 2nd to last byte in memory minus number */
		/* of bytes that wont change during calculation */
		_mul((total + len2 + len1 - 1 - shift_left), num1, len1, num2[i]);
		shift_left++;
	}
	total[len2 + len1] = '\0';

	for (i = 0; total[i] == '0'; i++)
		;
	if (total[i] != '\0')
		printf("%s\n", &total[i]);
	else
		printf("0\n");

	free(total);

	return (0);
}
