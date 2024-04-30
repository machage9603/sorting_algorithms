#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * listint - structure of a doubly linked list
 * @n: integer value in the node
 * @listint *prev: The previous value in the list
 * @listint *next: The next value in the list
 */
typedef struct listint
{
	const int n;
	struct listint *prev;
	struct listint *next;
} listint_t;

/** Sorting algorithm prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif
