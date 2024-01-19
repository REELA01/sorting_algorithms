#include "sort.h"
/**
 * swp_node - sawap between 2 nodes
 * @n1: first node pointer
 * @n2: second node pointer
 * Return: void value
*/
void swp_node(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}
/**
 * insertion_sort_list - sec sort alogrithim
 * @list: head node pointer
 * Return: void value
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *s1 ,*s2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	s1 = (*list)->next;
	while (s1 != NULL)
	{
		s2 = s1;
		s1 = s1->next;
		while(s2 != NULL && s2->prev != NULL)
		{
			if (s2->prev->n > s2->n)
			{
				swp_node(s2->prev, s2);
				if (s2->prev == NULL)
					*list = s2;
				print_list((const listint_t *)*list);
			}
			else
				s2 = s2->prev;
		}
	}
}
