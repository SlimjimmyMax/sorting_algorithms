#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: A double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		previous = current->prev;
		while (previous != NULL && current->n < previous->n)
		{
			current->prev = previous->prev;
			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*list = current;
			previous->next = next_node;
			if (next_node != NULL)
				next_node->prev = previous;
			previous->prev = current;
			current->next = previous;
			previous = current->prev;
			print_list((const listint_t *)*list);
		}
	}
}
