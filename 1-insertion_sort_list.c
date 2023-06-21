#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *sorted, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
sorted = current->prev;
temp = current;

while (sorted != NULL && sorted->n > current->n)
{
if (current->next != NULL)
current->next->prev = sorted;

sorted->next = current->next;
current->next = sorted;
current->prev = sorted->prev;

if (sorted->prev != NULL)
sorted->prev->next = current;
else
*list = current;

sorted->prev = current;

print_list(*list);

sorted = current->prev;
}

current = temp->next;
}
}
