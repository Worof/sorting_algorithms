#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, i, *count_arr, *output;
    
    if (size < 2)
        return;

    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count_arr = malloc(sizeof(int) * (max + 1));
    if (count_arr == NULL)
        return;

    for (i = 0; i <= max; i++)
        count_arr[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_arr[array[i]]++;

    for (i = 1; i <= max; i++)
        count_arr[i] += count_arr[i - 1];

    print_array(count_arr, max + 1);

    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(count_arr);
        return;
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count_arr[array[i]] - 1] = array[i];
        count_arr[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(output);
    free(count_arr);
}
