#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order using Cocktail Shaker Sort
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *current;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (swapped)
{
swapped = 0;
current = *list;

while (current->next != NULL)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}

if (!swapped)
break;

swapped = 0;
current = current->prev;

while (current->prev != NULL)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}
}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev != NULL)
node1->prev->next = node2;
else
*list = node2;

if (node2->next != NULL)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;
}
