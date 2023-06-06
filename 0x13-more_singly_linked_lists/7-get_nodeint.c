#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node
 *
 * @head: pointer
 * @index: nth element
 * Return: node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (!head)
		return (NULL);

	for (i = 0; (head && i < index); i++)
		head = head->next;
	if (i == index)
		return (head);

	return (NULL);
}
