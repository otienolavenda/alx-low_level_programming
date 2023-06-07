#include "lists.h"

/**
 * print_listint_safe - prints a list
 * @head: pointer
 * Return: the number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *first, *last;
	size_t count = 0;

	first = head;
	last = head;

	if (!head)
		exit(98);

	while (first && last && last->next)
	{
		first = first->next;
		last = last->next->next;
		count++;

		if (first == last)
		{
			printf("[%p] %d\n", (void *)first, first->n);
			first = first->next;
			while (first != last)
			{
				printf("[%p] %d\n", (void *)first, first->n);
				first = first->next;
				count++;
			}
			printf("[%p] %d\n", (void *)first, first->n);
			printf("-> [%p] %d\n", (void *)last, last->n);
			return (count);
		}
		printf("[%p] %d\n", (void *)first, first->n);
	}
	return (count);
}
