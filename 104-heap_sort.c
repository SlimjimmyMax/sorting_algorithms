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
 * max_heapify - Creates a max heap from a given root node.
 * @array: The array representing the heap.
 * @size: The total number of elements in the array.
 * @base: The number of elements to consider for max_heapify.
 * @root: The root node of the subtree to be heapified.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int l;

	if (array == NULL || size < 2)
		return;

	for (l = (size / 2) - 1; l >= 0; l--)
		max_heapify(array, size, size, l);

	for (l = size - 1; l > 0; l--)
	{
		swap_ints(array, array + l);
		max_heapify(array, size, l, 0);
	}
}
