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
 * hoare_partition - Implements the Hoare partition scheme.
 * @e_m: The array to be partitioned.
 * @size: The number of elements in the array.
 * @left: The left index of the subarray to partition.
 * @right: The right index of the subarray to partition.
 *
 * Return: The index of the partitioning element.
 */
int hoare_partition(int *e_m, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = e_m[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (e_m[above] < pivot);
		do {
			below--;
		} while (e_m[below] > pivot);

		if (above < below)
		{
			swap_ints(e_m + above, e_m + below);
			print_array(e_m, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Sorts a subarray using the Hoare partition scheme.
 * @e_m: The array to be sorted.
 * @size: The number of elements in the array.
 * @left: The left index of the subarray to sort.
 * @right: The right index of the subarray to sort.
 */
void hoare_sort(int *e_m, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(e_m, size, left, right);
		hoare_sort(e_m, size, left, part - 1);
		hoare_sort(e_m, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick Sort algorithm with Hoare partition scheme.
 * @e_m: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort_hoare(int *e_m, size_t size)
{
	if (e_m == NULL || size < 2)
		return;

	hoare_sort(e_m, size, 0, size - 1);
}
