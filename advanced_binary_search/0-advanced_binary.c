#include "search_algos.h"

/**
 * recursion - Recursive binary search helper
 * @array: Pointer to the first element of the array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int recursion(int *array, int left, int right, int value)
{
	int mid, i;

	if (left > right)
		return (-1);

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	mid = (left + right) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (recursion(array, left, mid, value));
	}
	if (array[mid] > value)
		return (recursion(array, left, mid - 1, value));
	else
		return (recursion(array, mid + 1, right, value));
}
/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (recursion(array, 0, (int)(size - 1), value));
}
