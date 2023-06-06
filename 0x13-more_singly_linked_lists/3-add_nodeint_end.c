#include "lists.h"

/**
 * add_nodeint_end - add node at end of list
 *
 * @head: pointer to pointer
 * @n: int
 * Return: address
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *list, *ahead = *head;

	list = malloc(sizeof(listint_t));

	if (!list)
		return (NULL);

	list->n = n;
	list->next = '\0';

	if (!ahead)
	{
		*head = list;
		return (list);
	}

	while (ahead->next)
		ahead = ahead->next;
	ahead->next = list;

	return (list);
}
