#ifndef SORT_H
#define SORT_H

/**
 * Predefined C Header files
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
