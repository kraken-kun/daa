#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and place the pivot element in its correct position
int partition(int arr[], int low, int high) {
    // Select the rightmost element as the pivot
    int pivot = arr[high];

    // Index of the smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot, swap it with the element at index i
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place the pivot element in its correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

// Function to perform Quick Sort on the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and obtain the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
