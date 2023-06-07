


































































#include "lists.h"

/**
 * free_listint_safe - free list
 *
 * @h: pointer to pointer
 * Return: size
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *list;
	size_t size = 0;
	int i;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		i = *h - (*h)->next;
		if (i > 0)
		{
			list = (*h)->next;
			free(*h);
			*h = list;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}
	*h = NULL;

	return (size);
}
