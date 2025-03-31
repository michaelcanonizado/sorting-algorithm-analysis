#include <stdio.h>
#include <stdlib.h>

int* generateRandomIntegers(int n);
int *generateIncreasingSequence(int n, int startingValue);

void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int n);
void quickSort(int arr[], int n);
void heapSort(int arr[], int n);

typedef struct {
    const char *name;
    double time;
    void (*function)(int[], int);
} SortingAlgorithm;
SortingAlgorithm algorithms[] = {
    {"Selection Sort", 0.0, selectionSort},
    {"Bubble Sort", 0.0,  bubbleSort},
    {"Insertion Sort", 0.0, insertionSort},
    {"Merge Sort", 0.0, mergeSort},
    {"Quick Sort", 0.0, quickSort},
    {"Heap Sort", 0.0, heapSort},
};
int algorithmsSize = sizeof(algorithms)/sizeof(algorithms[0]);

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

        int *unsortedArr;
        switch (selectedGenerationMethod) {
            case 1:
            case 2:
                unsortedArr = generateIncreasingSequence(numOfIntegers, 9);
                    
                printf("\n");
                for(int i = 0; i < numOfIntegers; i++) {
                    printf("%d,", unsortedArr[i]);
                }
            default:
                break;
        }
    }
    return 0;
}

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
