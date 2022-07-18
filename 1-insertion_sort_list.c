#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 *
 * @list: pointer to the first element of sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp;

	if (!list)
		return;

	for (head = *list; head; head = head->next)
	{
		while (head->next && (head->next->n < head->n))
		{
			temp = head->next;
			head->next = temp->next;
			temp->prev = head->prev;

			if (head->prev)
				head->prev->next = temp;
			if (temp->next)
				temp->next->prev = head;

			head->prev = temp;
			temp->next = head;

			if (temp->prev)
				head = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
	}
}
