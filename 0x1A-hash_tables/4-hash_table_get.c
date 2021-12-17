#include "hash_tables.h"

/**
 * hash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *cur;
	char *v_copy = NULL;

	if (ht == NULL || key == NULL)
		return (NULL);

	idx = key_index((const unsigned char *) key, ht->size);

	cur = (ht->array)[idx];
	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			v_copy = strdup(cur->value);
			break;
		}
		cur = cur->next;
	}
	return (v_copy);
}
