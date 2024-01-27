#include "sort.h"
#include <stdlib.h>

/**
 * get_max - finds the maximum number in an array of integers
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: the maximum number found in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * count_sort - performs count sort on an array according to the digit
 *              represented by exp
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 * @exp: exponent representing the digit to sort by
 */
void count_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    if (!output)
        return;

    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (ssize_t i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 *              the Radix sort algorithm
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int max = get_max(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(array, size, exp);
        print_array(array, size);
    }
}
