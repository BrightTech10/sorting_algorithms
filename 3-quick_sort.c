#include "sort.h"

/**
 * swap - swaps the position of two values
 *
 * @pos1: first position
 * @pos2: second position
 */
void swap(int *pos1, int *pos2)
{
	int temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}

/**
 * partition - splits an array into two partitions
 *
 * @array: array to be split
 * @lb: lower bound of @array
 * @ub: upper bound of @array
 * @size: size of array
 * Return: returns partition index
 */
size_t partition(int *array, size_t lb, size_t ub, size_t size)
{
	size_t i, j, pivot;

	pivot = ub;
	i = lb;

	for (j = i; j < ub; j++)
	{
		if (array[j] <= array[pivot])
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i += 1;
		}
	}
	if (i != j)
	{
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quickSort - sorts an array of integers
 *
 * @array: array to be sorted
 * @lb: lower bound of @array
 * @ub: upper bound of @array
 * @size: size of array
 */
void quickSort(int *array, size_t lb, size_t ub, size_t size)
{
	size_t index = 0;

	if (lb < ub && array)
	{
		index = partition(array, lb, ub, size);
		if (index - lb > 1)
			quickSort(array, lb, index - 1, size);
		if (ub - index > 1)
		quickSort(array, index + 1, ub, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array && size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
