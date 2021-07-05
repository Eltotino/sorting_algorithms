#include "sort.h"


/**
* swap - swaps doubly linked list node
* @one: the first node
* @two: the second node
*
* Return: void
*/
void swap(listint_t **one, listint_t **two)
{
	if ((*one)->prev)
			(*one)->prev->next = *two;
	if ((*two)->next)
			(*two)->next->prev = *one;
	(*one)->next = (*two)->next;
	(*two)->prev = (*one)->prev;
	(*two)->next = *one;
	(*one)->prev = *two;
}

/**
* cocktail_sort_list - sorts doubly linked list
* @list: doubly linked list
*
* Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	int node;

	if (!list || !*list)
		return;

	left = *list;
	do {
		node = 0;
		while (left->next)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap(&left, &right);
				if (!right->prev)
					*list = right;
				print_list(*list);
				node = 1;
			}
			else
				left = left->next;
		}
		right = left->prev;
		while (right->prev)
		{
			left = right->prev;
			if (right->n < left->n)
			{
				if (!left->prev)
					*list = right;
				swap(&left, &right);
				print_list(*list);
				node = 1;
			}
			else
				right = right->prev;
		}
	} while (node);
}
