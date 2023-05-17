#include <stdio.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // Compare elements from left and right subarrays and place them in the merged array in sorted order
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on an array
void mergeSort(int arr[], int size) {
    // Base case: if the array has 1 or 0 elements, it is already sorted
    if (size < 2) {
        return;
    }

    // Divide the array into two halves
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Copy elements from the original array into the left and right subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the left and right subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted left and right subarrays
    merge(arr, left, mid, right, size - mid);
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
