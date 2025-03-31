#include <stdio.h>
#include <stdlib.h>

/**
 * @struct SortingAlgorithm
 * @brief Represents the data of a sorting algorithm
 * @var name Name of the algorithm in title case
 * @var time Time taken for the algorithms to sort
 * @var function Function pointer to its algorithm
 * 
 * This object gives us OOP-like features. Allowing us to perform more complex logic such as iteration on the algorithms, sorting by time, and callbacks.
 */
typedef struct {
    const char *name;
    double time;
    void (*function)(int[], int);
} SortingAlgorithm;

/**
 * @brief The function that is called in random integers data generation case. 
 * @param n The number of integers to be sorted
 * @param algorithms The array of algorithms data that will hold the results
 * @param algorithmsSize The number of elements in algorithms array
 */
void methodRandomIntegers(int n);
/**
 * @brief The function that is called in increasing sequence data generation case. 
 * @param n The number of integers to be sorted
 * @param algorithms The array of algorithms data that will hold the results
 * @param algorithmsSize The number of elements in algorithms array
 */
void methodIncreasingSequence(int n);

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

/*
*
* SORTING ALGORITHMS
*
*/
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int n);
void quickSort(int arr[], int n);
void heapSort(int arr[], int n);

/**
 * 
 * UTILITIES
 * 
*/
void clearScreen();

SortingAlgorithm algorithms[] = {
    {"Selection Sort", 0.0, selectionSort},
    {"Bubble Sort", 0.0,  bubbleSort},
    {"Insertion Sort", 0.0, insertionSort},
    {"Merge Sort", 0.0, mergeSort},
    {"Quick Sort", 0.0, quickSort},
    {"Heap Sort", 0.0, heapSort},
};
int algorithmsSize = sizeof(algorithms)/sizeof(algorithms[0]);
int startingValue = 0;

int main(void) { 
    int isExit = 0;
    while(!isExit) {
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

        switch (selectedGenerationMethod) {
            case 1:
                methodRandomIntegers(numOfIntegers);
                break;
            case 2:
                methodIncreasingSequence(numOfIntegers);
                break;
            default:
                break;
        }

        printf("\n----------------------------------------");
        printf("\nSorting Algorithm Results");
        printf("\n----------------------------------------");
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
    }
    return 0;
}

/*
*
* DATA GENERATION METHOD CASES
*
*/
void methodRandomIntegers(int n) {
    int *unsortedArr = generateRandomIntegers(n);
                    
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d,", unsortedArr[i]);
    }
}
void methodIncreasingSequence(int n) {
    startingValue = 7;
    int *unsortedArr = generateIncreasingSequence(n, startingValue);
                    
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d,", unsortedArr[i]);
    }
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

/*
*
* SORTING ALGORITHMS
*
*/
void selectionSort(int arr[], int n) {
    printf("\nRunning selectionSort()");
    return;
}
void bubbleSort(int arr[], int n) {
    printf("\nRunning bubbleSort()");
    return;
}
void insertionSort(int arr[], int n) {
    printf("\nRunning insertionSort()");
    return;
}
void mergeSort(int arr[], int n) {
    printf("\nRunning mergeSort()");
    return;
}
void quickSort(int arr[], int n) {
    printf("\nRunning quickSort()");
    return;
}
void heapSort(int arr[], int n) {
    printf("\nRunning heapSort()");
    return;
}

void clearScreen() {
    #ifdef _WIN32
	    system("cls");
    #else
	    printf("\033[2J");
	    printf("\033[H");
    #endif
}