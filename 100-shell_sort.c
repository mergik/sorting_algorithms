#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using Shell sort algorithm with the Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/*calculate the initial gap value using the Knuth sequence*/
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	/*shell Sort with decreasing gap values*/
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/*Insertion Sort for each gap value*/
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/*print the array after each decrease in gap value*/
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
