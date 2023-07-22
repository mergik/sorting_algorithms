#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			/*Swap nodes*/
			if (temp->prev)
				temp->prev->next = current;
			if (current->next)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			temp->prev = current;
			current->next = temp;

			/*Update the list head if necessary*/
			if (!current->prev)
				*list = current;

			/*prints the list after each swap*/
			print_list(*list);

			temp = current->prev;
		}
		current = current->next;
	}
}
