#include "sort.h"
/**
 * selection_sort - the third sorting algorthim
 * @array: the array
 * @size: array size
 * Return: void value
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minn;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		minn = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minn])
				minn = j;
		}
		if (minn != i)
		{
			tmp = array[i];
			array[i] = array[minn];
			array[minn] = tmp;
			print_array(array, size);
		}
	}
}
