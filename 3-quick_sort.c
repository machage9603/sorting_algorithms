#include "sort.h"

/**
 * swapped - swaps two array values
 *
 * @array: an integer array
 * @x: first value index
 * @y: second value index
 *
 * Return: an array with a value
 */

void swapped(int **array, ssize_t x, ssize_t y)
{
	int temp;

	temp = (*array)[x];
	(*array)[x] = (*array)[y];
	(*array)[y] = temp;
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
	int middle;
	ssize_t i, j;

	middle = array[y];
	i = x;
	for (j = x; j < y; j++)
	{
		if (array[j] < middle)
		{
			if (i != j)
			{
				swapped(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[y] < array[i])
	{
		swapped(&array, i, y);
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
	ssize_t middle;

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
	ssize_t x = 0;
	ssize_t y = (size - 1);

	if (!array || size < 2)
		return;

	sorting(array, x, y, size);
}
