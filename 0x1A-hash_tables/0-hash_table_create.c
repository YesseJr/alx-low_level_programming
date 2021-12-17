#include "hash_tables.h"

/**
 * hash_table_create - create hash table given size
 * @size: size
 * Return: pointer to table; NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;

	if (size == 0)
		return (NULL);

	new = malloc(sizeof(hash_table_t));
	if (new != NULL)
	{
		new->array = malloc(sizeof(hash_node_t *) * size);
		if (new->array == NULL)
			return (NULL);
		new->size = size;
	}

	return (new);
}
