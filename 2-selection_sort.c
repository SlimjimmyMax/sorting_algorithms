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
 * selection_sort - Sorts an array of integers in ascending order using the
 *                 Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size:  The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t l, s;

	if (array == NULL || size < 2)
		return;

	for (l = 0; l < size - 1; l++)
	{
		min = array + l;
		for (s = l + 1; s < size; s++)
			min = (array[s] < *min) ? (array + s) : min;

		if ((array + l) != min)
		{
			swap_ints(array + l, min);
			print_array(array, size);
		}
	}
}
