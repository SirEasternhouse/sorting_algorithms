#include <stddef.h>
#include "sort.h"

/**
 *swap - swap variables
 *@a: 1st variable to swap
 *@b: 2nd varible to swap
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element
 */
size_t lomuto_partition(int *array, ptrdiff_t low, ptrdiff_t high, size_t size)
{
	size_t i;
	int pivot = array[high];
	ptrdiff_t j;

	i = (size_t)low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != (size_t)j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != (size_t)high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - Sorts the array using the Quick sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quicksort(int *array, ptrdiff_t low, ptrdiff_t high, size_t size)
{
	if (low < high)
	{
		size_t pi = lomuto_partition(array, low, high, size);
		/* Recursively sort elements before and after partition */
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
