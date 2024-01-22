#include "sort.h"
/**
 * merge_sort_comp - compare
 * @array: the org array
 * @start: the strat idx
 * @stop: the stop idx
 * @new_ar: other array
 * Return: void value
*/
void merge_sort_comp(int *array, size_t start, size_t stop, int *new_ar)
{
	size_t i = start, j, k, midd;

	j = midd = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, midd - start);
	printf("[right]: ");
	print_array(array + midd, stop - midd);
	for (k = start; k < stop; k++)
	{
		if (i < midd && (j >= stop || array[i] <= array[j]))
			new_ar[k] = array[i++];
		else
			new_ar[k] = array[j++];
	}
	printf("[Done]: ");
	print_array(new_ar + start, stop - start);
}
/**
 * merge_sort_split - splits every time
 * @array: the org array
 * @start: the strat idx
 * @stop: the stop idx
 * @new_ar: other array
 * Return: void value
*/
void merge_sort_split(int *array, size_t start, size_t stop, int *new_ar)
{
	size_t midd;

	midd = (start + stop) / 2;
	if (stop - start < 2)
		return;
	merge_sort_split(new_ar, start, midd, array);
	merge_sort_split(new_ar, midd, stop, array);
	merge_sort_comp(array, start, stop, new_ar);
}
/**
 * merge_sort - take copy and do merge sorting
 * @array: the array
 * @size: array size
 * Return: void value
*/
void merge_sort(int *array, size_t size)
{
	int *new_nod;
	size_t i;

	if (array == NULL || size < 2)
		return;
	new_nod = malloc(sizeof(int) * size);
	if (new_nod == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		new_nod[i] = array[i];
	}
	merge_sort_split(new_nod, 0, size, array);
	free(new_nod);
}
