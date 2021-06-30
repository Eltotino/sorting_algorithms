#include "sort.h"

/**
* selection_sort - sorts array in ascending order
* @array: array
* @size: size of array
*
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t a, b, min;
	int tmp;

	for (a = 0; a < size; a++)
	{
		min = a;
		for (b = a; b < size; b++)
		{
			if (array[b] < array[min])
				min = b;
		}
		if (min == a)
			continue;
		tmp = array[min];
		array[min] = array[a];
		array[a] = tmp;
		print_array(array, size);
	}
}
