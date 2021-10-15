#include <stdio.h>
#include <stdarg.h>
#include "lists.h"

size_t free_listint_safe (listint_t **h)
{
	listint_t *now;
	listint_t *next;
	int j;

	register short c = 0;
	if (!h || ! (*h))
	 return (c);
	 now = *h;
	 while (now)
	 {
		j = now - now -> next;
		if (j > 0)
	 }
	 next = new -> next;
	 free (now);
	 new = next;
	 c++;
}
else
{
	free (now);
	*h =NULL;
	c++;
	break;
}
}
*h =NULL;
return (c);
}
