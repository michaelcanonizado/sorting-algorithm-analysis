#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

/**
 * @struct SortingAlgorithm
 * @brief Represents the data of a sorting algorithm
 * @var name Name of the algorithm in title case
 * @var outputFile Name of the file where the sorted integers will be stored
 * @var time Time taken for the algorithms to sort
 * @var function Function pointer to its algorithm
 * 
 * This object gives us OOP-like features. Allowing us to perform more complex logic such as iteration on the algorithms, sorting by time, and callbacks.
 */
typedef struct {
    const char *name;
    const char *outputFile;
    double time;
    void (*function)(int[], int);
} SortingAlgorithm;

/**
 * @brief Generates an array of random integers.
 * @param n The size of the resulting array.
 * @return The dynamically allocated array. It needs to be manually freed when used.
 */
int *generateRandomIntegers(int n);
/**
 * @brief Generates an array of integers in increasing order
 * @param n The size of the resulting array
 * @param startingValue The value of the first element of the ordered array.
 * @return The dynamically allocated array. It needs to be manually freed when used.
 */
int *generateIncreasingSequence(int n, int startingValue);

/**
 * @brief temp
 * @param temp Temp
 */
void runBenchmark(int *array, int n);

/*
*
* SORTING ALGORITHMS
*
*/
void selectionSort(int array[], int n);
void bubbleSort(int array[], int n);
void insertionSort(int array[], int n);
void merge(int array[], int left, int mid, int right);
void mergeSortHelper(int array[], int left, int right);
void mergeSort(int array[], int n);
int quickSortPartition(int array[], int low, int high);
void quickSortHelper(int array[], int low, int high);
void quickSort(int array[], int n);
void heapSort(int array[], int n);

/**
 * 
 * UTILITIES
 * 
*/
void clearFile(const char *filename);
void appendStringToFile(const char *filename, const char *format, ...);
void appendArrayToFile(const char *filename, int *array, int n);
int* duplicateArray(const int *array, int n);
void clearScreen(void);
void displayHeader(void);
void displayConfirmExit(void);

SortingAlgorithm algorithms[] = {
    {"Selection Sort", "output/selection-sort.txt", 0.0, selectionSort},
    {"Bubble Sort", "output/bubble-sort.txt", 0.0,  bubbleSort},
    {"Insertion Sort", "output/insertion-sort.txt", 0.0, insertionSort},
    {"Merge Sort", "output/merge-sort.txt", 0.0, mergeSort},
    {"Quick Sort", "output/quick-sort.txt", 0.0, quickSort},
    {"Heap Sort", "output/heap-sort.txt", 0.0, heapSort},
};
int algorithmsSize = sizeof(algorithms)/sizeof(algorithms[0]);

int main(void) { 
    int isExit = 0;
    while(!isExit) {
        clearScreen();
        displayHeader();
        int numOfIntegers = 0;
        printf("\nNumber of integers (N): ");
        scanf("%d", &numOfIntegers);

        char *menuOptions[] = {
            "Random integers",
            "Increasing Sequence"
        };
        int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
        printf("Data Generation Method:");
        for(int i = 0; i < menuOptionsSize; i++) {
            printf("\n\t%d) %s", i+1, menuOptions[i]);
        }

        int selectedGenerationMethod = 0;
        printf("\nPlease choose a method: ");
        scanf("%d", &selectedGenerationMethod);

        int *unsortedArr, startingValue = 0;
        char *unsortedArrayOutputFile = "output/unsorted.txt";

        clearFile(unsortedArrayOutputFile);
        appendStringToFile(unsortedArrayOutputFile, "\nUnsorted Array | Number of elements (N): %d\n", numOfIntegers);

        switch (selectedGenerationMethod) {
            case 1:
                unsortedArr = generateRandomIntegers(numOfIntegers);
                
                appendArrayToFile(unsortedArrayOutputFile, unsortedArr, numOfIntegers);

                runBenchmark(unsortedArr, numOfIntegers);
                free(unsortedArr);
                break;
            case 2:
                printf("What is the starting value? (X): ");
                scanf("%d", &startingValue);
                unsortedArr = generateIncreasingSequence(numOfIntegers, startingValue);

                appendArrayToFile(unsortedArrayOutputFile, unsortedArr, numOfIntegers);

                runBenchmark(unsortedArr, numOfIntegers);
                free(unsortedArr);
                break;
            default:
                break;
        }

        clearScreen();
        displayHeader();
        printf("\nNumber of Elements (N): %d", numOfIntegers);
        printf("\nGeneration Method: ");
        if (selectedGenerationMethod == 1) {
            printf("Random Integers");
        } else if (selectedGenerationMethod == 2) {
            printf("Increasing Sequence");
        }
        if (selectedGenerationMethod == 2) {
            printf("\nStarting Value (X): %d", startingValue);
        }
        

        printf("\n----------------------------------------");
        printf("\n|  Rank |    Algorithm    |    Time    |");
        printf("\n----------------------------------------");
        for(int i = 0; i < algorithmsSize; i++) {
            printf("\n|%6d | %15s | %.9lf|", i+1, algorithms[i].name, algorithms[i].time);
        }
        printf("\n----------------------------------------");

        displayConfirmExit();
    }
    return 0;
}

/*
*
* DATA GENERATION METHODS
*
*/
int *generateRandomIntegers(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}
int *generateIncreasingSequence(int n, int startingValue) {
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        arr[i] = startingValue++;
    }
    return arr;
}

void runBenchmark(int *array, int n) {
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    appendStringToFile("results.csv", "\n");
    for(int i = 0; i < algorithmsSize; i++) {
        int* arrayCopy = duplicateArray(array, n);

        QueryPerformanceCounter(&start);
        algorithms[i].function(arrayCopy, n);
        QueryPerformanceCounter(&end);

        algorithms[i].time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        clearFile(algorithms[i].outputFile);
        appendStringToFile(algorithms[i].outputFile, "\n%s Sorted Array | Number of elements (N): %d | Time take: %.9lf\n",algorithms[i].name, n, algorithms[i].time);
        appendArrayToFile(algorithms[i].outputFile, arrayCopy, n);

        appendStringToFile("results.csv", "%.9lf,", algorithms[i].time);
    }
}

/*
*
* SORTING ALGORITHMS
*
*/
void selectionSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        // Stop if already sorted
        if (!swapped) break;
    }
}
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        // Store the current element
        int key = array[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // Insert key at the correct position
        array[j + 1] = key;
    }
}
void merge(int array[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Allocate memory dynamically
    int* leftArray = (int*)malloc(leftSize * sizeof(int));
    int* rightArray = (int*)malloc(rightSize * sizeof(int));

    // Check for memory allocation failure
    if (leftArray == NULL || rightArray == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    // Merge the temporary arrays back into the main array
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }

    // Copy remaining elements of leftArray
    while (i < leftSize) {
        array[k++] = leftArray[i++];
    }
    // Copy remaining elements of rightArray
    while (j < rightSize) {
        array[k++] = rightArray[j++];
    }

    // Free dynamically allocated memory
    free(leftArray);
    free(rightArray);
}
void mergeSortHelper(int array[], int left, int right) {
    if (left < right) {
        // Find the middle index
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSortHelper(array, left, mid);
        mergeSortHelper(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}
void mergeSort(int array[], int n) {
    mergeSortHelper(array, 0, n - 1);
}
int quickSortPartition(int array[], int low, int high) {
    // Choose the pivot element (last element)
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot, swap
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Place pivot at its correct position
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}
void quickSortHelper(int array[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = quickSortPartition(array, low, high);
        // Recursively sort elements before and after partition
        quickSortHelper(array, low, pivotIndex - 1);
        quickSortHelper(array, pivotIndex + 1, high);
    }
}
void quickSort(int array[], int n) {
    quickSortHelper(array, 0, n - 1);
}
void heapSort(int array[], int n) {
    for(int i = 0; i < 100000; i++);
    printf("\nRunning heapSort()");
    return;
}

void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fclose(file);
}
void appendStringToFile(const char *filename, const char *format, ...) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);

    fclose(file);
}
void appendArrayToFile(const char *filename, int *array, int n) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d", array[i]);
        if (i < n - 1) {
            fprintf(file, ",");
        }
        if ((i+1) % 20 == 0) {
            fprintf(file, "\n");
        }
    }
    fprintf(file, "\n");

    fclose(file);
}
int* duplicateArray(const int *array, int n) {
    int *copy = malloc(n * sizeof(int));
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        copy[i] = array[i];
    }
    return copy;
}
void clearScreen(void) {
    #ifdef _WIN32
	    system("cls");
    #else
	    printf("\033[2J");
	    printf("\033[H");
    #endif
}
void displayHeader(void) {
    printf("\n----------------------------------------");
    printf("\n       Sorting Algorithm Analysis");
    printf("\n----------------------------------------");
}
void displayConfirmExit(void) {
    char response;
    do {
        printf("\nEnter Y/y to exit: ");
        scanf(" %c", &response);
        response = toupper(response);
        if (response != 'Y') {
            while (getchar() != '\n');
        }
    } while(response != 'Y');
}