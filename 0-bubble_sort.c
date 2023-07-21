#include "sort.h"

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*swaps the elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*sets the swapped flag to true*/
				swapped = 1;

				/*prints the array after each swap*/
				print_array(array, size);
			}
		}

		/*If no elements were swapped in the inner loop*/
		/*the array is already sorted*/
		if (swapped == 0)
			break;
	}
}
