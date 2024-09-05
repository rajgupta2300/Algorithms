#include <stdio.h>
#include <limits.h> // For INT_MAX

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int key = 0, j = 0, i = 0;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i = 0, j = 0, min = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i = 0, j = 0, flag = 0;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break; // Array is already sorted
    }
}

// Merge Function
void merge(int A[], int p, int q, int r) {
    int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (i = 0; i < n1; i++) L[i] = A[p + i];
    for (j = 0; j < n2; j++) R[j] = A[q + 1 + j];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// Merge Sort
void mergeSort(int A[], int p, int r) {
    int q = 0;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// Partition Function for Quick Sort
int partition(int arr[], int p, int r) {
    int pivot = 0, i = 0, j = 0;
    pivot = arr[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int p, int r) {
    int q = 0;
    if (p < r) {
        q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

// Max-Heapify
void maxHeapify(int A[], int n, int i) {
    int l = 0, r = 0, largest = 0;
    l = 2 * i + 1;
    r = 2 * i + 2;
    largest = i;
    if (l < n && A[l] > A[i]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;
    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, n, largest);
    }
}

// Build Max-Heap
void buildMaxHeap(int A[], int n) {
    int i = 0;
    for (i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

// Heap Sort
void heapSort(int A[], int n) {
    int i = 0;
    buildMaxHeap(A, n);
    for (i = n - 1; i >= 1; i--) {
        swap(&A[0], &A[i]);
        maxHeapify(A, i, 0);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

// Binary Search (Iterative)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

// Input Array
void input_array(int A[], int n) {
    int i = 0;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
}

// Output Array
void output_array(int A[], int n) {
    int i = 0;
    printf("\nCurrent Array: ");
    for (i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

// Main Function
int main() {
    int n = 0, choice = 0, key = 0, index = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }
    int A[n];
    input_array(A, n);

    while (1) {
        printf("\n==================== MENU ====================\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Linear Search\n");
        printf("8. Binary Search\n");
        printf("9. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionSort(A, n);
                printf("Array sorted using Insertion Sort.");
                break;
            case 2:
                selectionSort(A, n);
                printf("Array sorted using Selection Sort.");
                break;
            case 3:
                bubbleSort(A, n);
                printf("Array sorted using Bubble Sort.");
                break;
            case 4:
                mergeSort(A, 0, n - 1);
                printf("Array sorted using Merge Sort.");
                break;
            case 5:
                quickSort(A, 0, n - 1);
                printf("Array sorted using Quick Sort.");
                break;
            case 6:
                heapSort(A, n);
                printf("Array sorted using Heap Sort.");
                break;
            case 7:
                printf("Enter the element to search (Linear Search): ");
                scanf("%d", &key);
                index = linearSearch(A, n, key);
                if (index != -1) {
                    printf("Element found at index %d.", index);
                } else {
                    printf("Element not found.");
                }
                break;
            case 8:
                printf("Enter the element to search (Binary Search): ");
                scanf("%d", &key);
                index = binarySearch(A, n, key);
                if (index != -1) {
                    printf("Element found at index %d.", index);
                } else {
                    printf("Element not found.");
                }
                break;
            case 9:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.");
                break;
        }

        // Automatically print the array after each operation
        output_array(A, n);
    }

    return 0;
}
