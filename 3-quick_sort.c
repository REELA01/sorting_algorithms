#include "sort.h"
/**
 * swp_node - do swapping
 * @array: the array
 * @size: size of array
 * @n1: the first int pointr to swap
 * @n2: The second int pointer to swap
 * Return: void value
*/
void swp_node(int *array, size_t size, int *n1, int *n2)
{
	if (*n1 != *n2)
	{
		*n1 = *n1 + *n2;
		*n2 = *n1 - *n2;
		*n1 = *n1 - *n2;
		print_array((const int *)array, size);
	}
}
/**
 * lomuto_partition - do partiton for sorting
 * @array: the array
 * @size: the size of array
 * @left: the start idx
 * @right: the ending idx
 * Return: the final partition idx
*/
size_t lomuto_partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int i, j, piv = array[right];

	for (i = j = left; j < right; j++)
	{
		if (array[j] < piv)
			swp_node(array, size, &array[j], &array[i++]);
	}
	swp_node(array, size, &array[i], &array[right]);
	return (i);
}
/**
 * lquick_sort - the base implemantiation of the algrthim
 * @array: the array
 * @size: the size of array
 * @left: the starte idx
 * @right: The ending idx
 * Return: void value
*/
void lquick_sort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t p = lomuto_partition(array, size, left, right);

		lquick_sort(array, size, left, p - 1);
		lquick_sort(array, size, p + 1, right);
	}
}
/**
 * quick_sort - forth sourting algrorithim
 * @array: the array
 * @size: size of array
 * Return: void value
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;
	lquick_sort(array, size, 0, size - 1);
}
