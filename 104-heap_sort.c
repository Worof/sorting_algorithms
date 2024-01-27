#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * @array: The entire array, needed for printing
 * @size: The size of the array, needed for printing
 */
void swap(int *a, int *b, int *array, size_t size)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    print_array(array, size);
}

/**
 * sift_down - Repairs the heap whose root element is at index 'start'
 * @array: The array to be sorted
 * @start: The index of the root of the heap
 * @end: The end index of the heap
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start, child, swap_idx;

    while ((root * 2 + 1) <= end) { /*While the root has at least one child*/
        child = root * 2 + 1;       /* Left child*/
        swap_idx = root;            /*Keeps track of child to swap with*/

        if (array[swap_idx] < array[child])
            swap_idx = child;
        /*If the right child exists and is greater than the left child*/
        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;
        if (swap_idx == root)
            return; /**
		     * The root holds the largest element. Since we assume
                     * the heaps rooted at the children are valid, this means
                     * that we are done.
		     */
        else {
            swap(&array[root], &array[swap_idx], array, size);
            root = swap_idx; /*Repeat to continue sifting down the child now*/
        }
    }
}

/**
 * heapify - Turns an array into a heap
 * @array: The array to be heapified
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    ssize_t start = (size - 2) / 2; /*Last parent node*/

    while (start >= 0) {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (size < 2)
        return;

    heapify(array, size);

    end = size - 1;
    while (end > 0) {
        swap(&array[end], &array[0], array, size);
        end--;
        sift_down(array, 0, end, size);
    }
}
