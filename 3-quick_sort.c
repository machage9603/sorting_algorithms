#include "sort.h"
#include <stdio.h>
#include <unistd.h>

/**
 * swapped - swaps two array values
 *
 * @array: an integer array
 * @x: first value index
 * @y: second value index
 *
 * Return: an array with a value
 */

void swapped(int *array, ssize_t x, ssize_t y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/**
 * subdivision - chooses an array middle point
 *
 * @array: the input array to sort
 * @x: the subdivision's lowest index
 * @y: the subdivision's highest index
 * @size: the array size
 *
 * Return: index of the partition
 */
size_t subdivision(int *array, ssize_t x, ssize_t y, size_t size)
{
	int middle = array[y];
	ssize_t i = x, j;

	for (j = x; j < y; j++)
		;
	{
		if (array[j] < middle)
		{
			if (array[i] != array[j])
			{
				swapped(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[y])
	{
		swapped(array, i, y);
		print_array(array, size);
	}

	return (i);
}

/**
 * sorting - subdivides the array, then sorts each subdivision
 *
 * @array: the input array to sort
 * @x: the subdivision's lowest index
 * @y: the subdivision's highest index
 * @size: the array size
 */

void sorting(int *array, ssize_t x, ssize_t y, size_t size)
{
	ssize_t middle = 0;

	if (x < y)
	{
		middle = subdivision(array, x, y, size);
		sorting(array, x, middle - 1, size);
		sorting(array, middle + 1, y, size);
	}
}

/**
 * quick_sort - quicksort algorithm sorting an int array
 *
 * @array: the integer array
 * @size: the array size
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sorting(array, 0, size - 1, size);
}
