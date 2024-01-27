#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (current = (*list)->next; current != NULL; current = temp)
    {
        temp = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->next->prev;
            current->next->prev = current;

            if (current->prev != NULL)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);
        }
    }
}
