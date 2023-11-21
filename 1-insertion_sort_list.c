#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - insertion sort
 * @list: pointer to linked list head
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *before;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		before = current->prev;

		while (before != NULL && before->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = before;

			if (before->prev != NULL)
				before->prev->next = temp;
			else
				*list = temp;

			before->next = temp->next;
			temp->prev = before->prev;
			temp->next = before;
			before->prev = temp;

			before = temp->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
