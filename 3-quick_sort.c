#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @e_m: Pointer to the first integer.
 * @b_k: Pointer to the second integer.
 */
void swap_ints(int *e_m, int *b_k)
{
	int tmp;
	tmp = *e_m;
	*e_m = *b_k;
	*b_k = tmp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @size:  The number of elements in the array.
 * @left:  The left index of the partition.
 * @right: The right index of the partition.
 *
 * Return: The index of the pivot element.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return above;
}

/**
 * lomuto_sort - Sorts an array of integers using the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size:  The number of elements in the array.
 * @left:  The left index of the partition.
 * @right: The right index of the partition.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size:  The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
