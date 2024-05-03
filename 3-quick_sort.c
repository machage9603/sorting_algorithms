#include "sort.h"

/**
 * swapped - swaps two elements in an array
 * @a: the first element
 * @b: the second element
 */

void swapped(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * subdivision - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @l: first index of array
 * @h: last index of array
 * Return: new index position
 */
int subdivision(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swapped(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swapped(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * sorting - implement the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @l: first index of the array
 * @h: the last index of the array
 * Return: 0
 */

void sorting(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = subdivision(array, size, l, h);
		sorting(array, size, l, i - 1);
		sorting(array, size, i + 1, h);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sorting(array, size, 0, size - 1);
}
