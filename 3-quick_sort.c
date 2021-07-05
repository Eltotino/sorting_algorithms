#include "sort.h"

/**
* change - swaps two ints
* @one: first int
* @two: second int
*
* Return: void
*/
void change(int *one, int *two)
{
	int tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

/**
* partition - seperates array by pivot
* @array: array
* @low: lowest value
* @high: highest value
* @size: size of the array
*
* Return: pivot position(int)
*/
int partition(int *array, int low, int high, size_t size)
	{
		int pivot = high;
		int a = low - 1, b;

		for (b = low; b <= high; b++)
		{
			if (array[b] <= array[pivot])
			{
				a++;
				if (a != b)
				{
					change(&array[a], &array[b]);
					print_array(array, size);
				}
			}
		}
	return (a);
	}
/**
* Lomuto_sort - sorts an array of int recursively
* @array: array
* @high: highest value
* @low: lowest value
* @size: size of the array
*
* Return: void
*/
void Lomuto_sort(int *array, int low, int high, size_t size)
{
		int part;

		if (low < high)
		{
			part = partition(array, low, high, size);
			Lomuto_sort(array, low, part - 1, size);
			Lomuto_sort(array, part + 1, high, size);
		}
}

/**
* quick_sort - sorts an array of int
* @array: array
* @size: size of array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	Lomuto_sort(array, 0, size - 1, size);
}
