#include <stdio.h>

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
    int arr[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < algorithmsSize; i++) {
        algorithms[i].function(arr,1);
    }
    
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
            case 2:
            default:
                break;
        }
    }
    return 0;
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
