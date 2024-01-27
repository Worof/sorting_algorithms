#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Data Structure for Doubly Linked List */
typedef struct listint_s
{
    const int n; /* Integer stored in the node */
    struct listint_s *prev; /* Pointer to the previous element of the list */
    struct listint_s *next; /* Pointer to the next element of the list */
} listint_t;

/* Function Prototypes */

/* Function to print an array of integers */
void print_array(const int *array, size_t size);

/* Function to print a list of integers */
void print_list(const listint_t *list);

/* Bubble sort function */
void bubble_sort(int *array, size_t size);
/* Insertion sort function*/
void insertion_sort_list(listint_t **list);
/* Selection sort function*/
void selection_sort(int *array, size_t size);
/* Quick sort function*/
void quick_sort(int *array, size_t size);
/* Add other sorting algorithm prototypes as needed */

#endif /* SORT_H */
