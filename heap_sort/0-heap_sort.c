#include "sort.h"
#include <stddef.h>

/**
 * swap - Swaps two integers
 * @a: First integer pointer
 * @b: Second integer pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * sift_down - Maintains the heap property
 * @array: Array to heapify
 * @size: Current size of heap
 * @i: Current node index
 * @t_size: Total size of array
 */
void sift_down(int *array, size_t size, size_t i, size_t t_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, t_size);
		sift_down(array, size, largest, t_size);
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int last_parent, i;

	if (!array || size < 2)
		return;

	last_parent = (size / 2) - 1;

	for (i = last_parent; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
