#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list
* @list: the list to be sorted
*
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *back, *next;

	if (!list || !*list || !(*list)->next)
		return;
	next = (*list)->next;
	while (next)
	{
		back = next;
		while (back->prev)
		{
			tmp = back->prev;
			if (back->n < tmp->n)
			{
				tmp->next = back->next;
				back->prev = tmp->prev;
				if (back->next)
					back->next->prev = tmp;

				if (tmp->prev)
					tmp->prev->next = back;
				else
					*list = back;
				back->next = tmp;
				tmp->prev = back;
				print_list(*list);
				continue;
			}
			back = back->prev;
		}
		next = next->next;
	}
}
