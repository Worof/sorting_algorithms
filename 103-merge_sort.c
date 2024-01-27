#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Temp array for left half
 * @left_size: Size of left subarray
 * @right: Temp array for right half
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
}

/**
 * merge_sort_recursive - Helper function to sort an array of integers
 * @array: The array to be sorted
 * @temp: Temporary array for merge operation
 * @size: Number of elements in array
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
    size_t mid, i;

    if (size < 2)
        return;

    mid = size / 2;

    for (i = 0; i < mid; i++)
        temp[i] = array[i];
    merge_sort_recursive(temp, array, mid);

    for (i = mid; i < size; i++)
        temp[i] = array[i];
    merge_sort_recursive(temp + mid, array + mid, size - mid);

    merge(array, temp, mid, temp + mid, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, size);
    free(temp);
}
