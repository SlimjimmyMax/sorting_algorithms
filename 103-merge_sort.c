#include "sort.h"

/**
 * merge_subarr - Merges two subarrays into one sorted subarray.
 * @e_m:   The array containing the subarrays.
 * @buff:  Temporary buffer array for merging.
 * @front: Starting index of the first subarray.
 * @mid:   Ending index of the first subarray and starting index of the second subarray.
 * @back:  Ending index of the second subarray.
 */
void merge_subarr(int *e_m, int *buff, size_t front, size_t mid, size_t back)
{
	size_t l, s, d = 0;

	printf("Merging...\n[left]: ");
	print_array(e_m + front, mid - front);

	printf("[right]: ");
	print_array(e_m + mid, back - mid);

	for (l = front, s = mid; l < mid && s < back; d++)
		buff[d] = (e_m[l] < e_m[s]) ? e_m[l++] : e_m[s++];
	for (; l < mid; l++)
		buff[d++] = e_m[l];
	for (; s < back; s++)
		buff[d++] = e_m[s];
	for (l = front, d = 0; l < back; l++)
		e_m[l] = buff[d++];

	printf("[Done]: ");
	print_array(e_m + front, back - front);
}

/**
 * merge_sort_recursive - Recursively sorts an array using the merge sort algorithm.
 * @e_m:   The array to be sorted.
 * @buff:  Temporary buffer array for merging.
 * @front: Starting index of the current subarray.
 * @back:  Ending index of the current subarray.
 */
void merge_sort_recursive(int *e_m, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(e_m, buff, front, mid);
		merge_sort_recursive(e_m, buff, mid, back);
		merge_subarr(e_m, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge Sort algorithm.
 * @e_m:   The array to be sorted.
 * @size:  The number of elements in the array.
 */
void merge_sort(int *e_m, size_t size)
{
	int *buff;

	if (e_m == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(e_m, buff, 0, size);

	free(buff);
}
