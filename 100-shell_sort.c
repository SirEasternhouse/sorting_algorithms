#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Determine the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			/* Shift elements until the correct position is found */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		/* Print the array after each decrease in the gap */
		print_array(array, size);
		/* Calculate the next gap using the Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
