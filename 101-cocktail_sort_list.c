#include "sort.h"

/**
 * swap_nodes_ahead - Swaps a node with its next node in a doubly linked list.
 * @list: A double pointer to the head of the linked list.
 */
void swap_nodes_ahead(listint_t **list)
{
	listint_t *tmp = (*list)->next;

	if ((*list)->prev != NULL)
		(*list)->prev->next = tmp;
	else
		(*list)->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = *list;
	else
		(*list)->prev = tmp;
	(*list)->next = tmp->next;
	tmp->prev = (*list)->prev;
	tmp->next = *list;
	(*list)->prev = tmp;
	*list = tmp;
}

/**
 * swap_nodes_behind - Swaps a node with its
 * previous node in a doubly linked list.
 * @list: A double pointer to the head of the linked list.
 */
void swap_nodes_behind(listint_t **list)
{
	listint_t *tmp = (*list)->prev;

	if ((*list)->next != NULL)
		(*list)->next->prev = tmp;
	else
		(*list)->prev = tmp;
	if (tmp->prev != NULL)
		tmp->prev->next = *list;
	else
		(*list)->prev = tmp;
	(*list)->next = tmp->next;
	tmp->prev = (*list)->prev;
	tmp->next = *list;
	(*list)->prev = tmp;
	*list = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail Shaker (Bidirectional
 *                     Bubble Sort) algorithm.
 * @list: A double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool sorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!sorted)
	{
		sorted = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes_ahead(&current);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
		for (current = tail; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes_behind(&current);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
	}
}
