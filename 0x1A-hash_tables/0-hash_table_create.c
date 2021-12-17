#include "hash_tables.h"

/**
 * hash_table_create - create hash table given size
 * @size: size
 * Return: pointer to table; NULL if error
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *J11;
	hash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
		return (NULL);

	J11 = malloc(sizeof(hash_table_t));
	if (!J11)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}

	J11->size = size;
	J11->array = array;

	return (J11);
}
