#include "sort.h"

/**
* bubble_sort - sorts an array in ascending order
* @array: array
* @size: size of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < (size - 1 - a); b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = tmp;
				print_array(array, size);
			}
		}
	}
}
