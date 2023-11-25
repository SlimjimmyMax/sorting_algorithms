#include "sort.h"

/**
 * get_max - Finds the maximum element in an array.
 * @array: The array to find the maximum element in.
 * @size:  The number of elements in the array.
 *
 * Return: The maximum element in the array.
 */
int get_max(int *array, int size)
{
	int max, l;

	for (max = array[0], l = 1; l < size; l++)
	{
		if (array[l] > max)
			max = array[l];
	}

	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size:  The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, l;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (l = 0; l < (max + 1); l++)
		count[l] = 0;
	for (l = 0; l < (int)size; l++)
		count[array[l]] += 1;
	for (l = 0; l < (max + 1); l++)
		count[l] += count[l - 1];

	for (l = 0; l < (int)size; l++)
	{
		sorted[count[array[l]] - 1] = array[l];
		count[array[l]] -= 1;
	}

	for (l = 0; l < (int)size; l++)
		array[l] = sorted[l];

	free(sorted);
	free(count);
}
