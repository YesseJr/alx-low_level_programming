#include "hash_tables.h"
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
