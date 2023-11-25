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
 * bitonic_merge - Merges two bitonic sequences.
 * @e_m: The array to be sorted.
 * @size: The number of elements in the array.
 * @start: The starting index of the sequence.
 * @seq: The length of the sequence.
 * @flow: The direction of the merge (UP or DOWN).
 */
void bitonic_merge(int *e_m, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t l, jump = seq / 2;

	if (seq > 1)
	{
		for (l = start; l < start + jump; l++)
		{
			if ((flow == UP && e_m[l] > e_m[l + jump]) ||
					(flow == DOWN && e_m[l] < e_m[l + jump]))
				swap_ints(e_m + l, e_m + l + jump);
		}
		bitonic_merge(e_m, size, start, jump, flow);
		bitonic_merge(e_m, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Recursively creates a bitonic sequence.
 * @e_m: The array to be sorted.
 * @size: The number of elements in the array.
 * @start: The starting index of the sequence.
 * @seq: The length of the sequence.
 * @flow: The direction of the sequence (UP or DOWN).
 */
void bitonic_seq(int *e_m, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(e_m + start, seq);

		bitonic_seq(e_m, size, start, cut, UP);
		bitonic_seq(e_m, size, start + cut, cut, DOWN);
		bitonic_merge(e_m, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(e_m + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic Sort algorithm.
 * @e_m: The array to be sorted.
 * @size: The number of elements in the array.
 */
void bitonic_sort(int *e_m, size_t size)
{
	if (e_m == NULL || size < 2)
		return;

	bitonic_seq(e_m, size, 0, size, UP);
}
