#include <stdio.h>
#include <stddef.h>

// Прототипи функцій
void process_array(int *arr, size_t size);
void print_array(const int *arr, size_t size);

int main(void) {
    int arr[] = {5, 8, 3, -4, 7, 9, -2, 6};
    size_t size = sizeof(arr) / sizeof(*arr);

    printf("Array before: ");
    print_array(arr, size);

    process_array(arr, size);

    printf("Array after:  ");
    print_array(arr, size);

    return 0;
}

// Обробка масиву через покажчики
void process_array(int *arr, size_t size) {
    if (arr == NULL || size == 0) {
        return;
    }

    int *ptr = arr;
    int *end = arr + size;

    while (ptr < end && *ptr >= 0) {
        ptr++;
    }

    if (ptr == end) {
        return;
    }

    ptr++;

    while (ptr < end) {
        *ptr = 0;
        ptr++;
    }
}

// Виведення масиву
void print_array(const int *arr, size_t size) {
    if (arr == NULL) {
        return;
    }

    const int *ptr = arr;
    const int *end = arr + size;

    while (ptr < end) {
        printf("%d ", *ptr);
        ptr++;
    }

    printf("\n");
}