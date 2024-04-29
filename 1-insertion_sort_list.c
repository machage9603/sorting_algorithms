#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Function sorting a doubly linked list
 *
 * @list: A pointer's address to the list's head
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node_1, *node_2;

	if (*list == NULL || list == NULL)
		return;

	node_1 = (*list)->next;

	while (node_1 != NULL)
	{
		node_2 = node_1->next;
		while (node_1->prev != NULL && node_1->prev->n > node_1->n)
		{
			node_1->prev->next = node_1->next;

			if (node_1->next)
				node_1->next->prev = node_1->prev;

			node_1->next = node_1->prev;
			node_1->prev = node_1->next->prev;
			node_1->next->prev = node_1;

			if (!node_1->prev)
				*list = node_1;
			else
				node_1->prev->next = node_1;
			print_list(*list);
		}
		node_1 = node_2;
	}
}
