#include "lists.h"

/**
 * free_listint2 - frees a list
 * @head: pointer
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *ptr;

	if (!head)
		return;

	while (*head)
	{
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}
