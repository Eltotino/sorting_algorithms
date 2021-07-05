#include "sort.h"

/**
* shell_sort - sorts array
* @array: array
* @size: size
*
* Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t a, b;
	size_t btwn = 1;
	int insert;

	if (!array || !size)
		return;
	while (btwn < size / 3)
		btwn = btwn * 3 + 1;
	while (btwn > 0)
	{
		for (a = btwn; a < size; a++)
		{
			insert = array[a];
			b = a;
			while (b > (btwn - 1) && array[b - btwn] >= insert)
			{
				array[b] = array[b - btwn];
				b -= btwn;
			}
			array[b] = insert;
		}
		btwn /= 3;
		print_array(array, size);
	}
}
