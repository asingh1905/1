//linear and binary search
#include <stdio.h>

// Function for Linear Search
void linearSearch(int arr[], int size, int to_find) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == to_find) {
            printf("Element %d found at arr[%d]\n", to_find, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", to_find);
    }
}

// Function for Binary Search (requires sorted array)
void binarySearch(int arr[], int size, int to_find) {
    int left = 0, right = size - 1, found = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == to_find) {
            printf("Element %d found at arr[%d]\n", to_find, mid);
            found = 1;
            break;
        }
        if (arr[mid] > to_find) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", to_find);
    }
}

// Function to sort an array (needed for binary search)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the array values:\n");
    for (int i = 0; i < size; i++) {
        printf("Element-%d: ", i);
        scanf("%d", &arr[i]);
    }

    int choice, to_find;
    printf("\nChoose Search Algorithm:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search for: ");
    scanf("%d", &to_find);

    if (choice == 1) {
        linearSearch(arr, size, to_find);
    } else if (choice == 2) {
        bubbleSort(arr, size); // Sorting for binary search
        printf("Sorted array: ");
        printArray(arr, size);
        binarySearch(arr, size, to_find);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
