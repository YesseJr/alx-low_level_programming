#include "hash_tables.h"

/**
 * hash_table_create - create hash table given size
 * @size: size
 * Return: pointer to table; NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	hash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
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

	ht->size = size;
	ht->array = array;

	return (ht);
}


/**
 * hash_djb2 - implement djb2 algorithm (one of best string hash functions)
 *
 * @str: value
 * Return: key
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}

/**
 * key_index - gives index of a key
 * @key: key
 * @size: size of hash table array
 * Return: index where key/value pair is stored in hash table array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

/**
 * hash_table_set - adds element hash table
 * @ht: hast table
 * @key: key hash table
 * @value: value key
 *
 * Return: 1 succeeded, 0 fail
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hnode = NULL;
	hash_node_t *collnode = NULL;
	unsigned long int index;
	char *valueup = NULL;
	char *keyup = NULL;

	if (!ht || !(ht->array) || !key || !key[0])
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	hnode = ht->array[index];
	valueup = strdup(value);
	if (!valueup)
		return (0);

	while (hnode != NULL)
	{
		if (!strcmp(hnode->key, key))
		{
			free(hnode->value);
			hnode->value = valueup;
			return (1);
		}
		hnode = hnode->next;
	}

	hnode = ht->array[index];

	collnode = malloc(sizeof(hash_node_t));
	if (collnode == NULL)
		return (free(valueup), 0);

	keyup = strdup(key);
	if (!keyup)
		return (free(valueup), free(collnode), 0);
	collnode->key = keyup;
	collnode->value = valueup;
	collnode->next = hnode;
	ht->array[index] = collnode;
	return (1);
}


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

/**
 * hash_table_print - prints hashtable
 * @ht: the hash table you want to print
 */

void hash_table_print(const hash_table_t *ht)
{

unsigned long int i;
hash_node_t *node;
short int J11 = 0;

if (ht == NULL)
	return;

putchar('{');
for (i = 0; i < ht->size; i++)
{
	node = ht->array[i];
	while (node != NULL)
	{
		if (J11)
			printf(", ");

		printf("'%s': '%s'", node->key, node->value);
		node = node->next;

		if (J11 == 0)
			J11 = 1;
	}
}
printf("}\n");
}

/**
 * hash_table_delete - delete a hash table
 * @ht: hash table
 *
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *hnode, *tmp;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < (ht->size); i++)
	{
		hnode = ht->array[i];
		while (hnode)
		{
			tmp = hnode->next;
			free(hnode->key);
			free(hnode->value);
			free(hnode);
			hnode = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
