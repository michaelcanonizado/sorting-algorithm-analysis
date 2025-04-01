SortingAlgorithm algorithms[] = {
    {"Selection Sort", "output/selection-sort.txt", 0.0, selectionSort},
    {"Bubble Sort", "output/bubble-sort.txt", 0.0,  bubbleSort},
    {"Insertion Sort", "output/insertion-sort.txt", 0.0, insertionSort},
    {"Merge Sort", "output/merge-sort.txt", 0.0, mergeSort},
    {"Quick Sort", "output/quick-sort.txt", 0.0, quickSort},
    {"Heap Sort", "output/heap-sort.txt", 0.0, heapSort},
};
int algorithmsSize = sizeof(algorithms)/sizeof(algorithms[0]);