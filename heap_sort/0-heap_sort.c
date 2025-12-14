#include "sort.h"
#include <stddef.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sift_down(int *array, size_t size, size_t i, size_t t_size) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        print_array(array, t_size);
        sift_down(array, size, largest, t_size);
    }
}

void heap_sort(int *array, size_t size) {
    if (!array || size < 2)
        return;

    int last_parent = (size / 2) - 1;
    
    for (int i = last_parent; i >= 0; i--)
        sift_down(array, size, i, size);

    for (size_t i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0, size);
    }
}
