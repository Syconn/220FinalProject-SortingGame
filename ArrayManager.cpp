//
// Created by Aidan on 10/2/2025.
//

#include "Sorter.h"
#include "ArrayUtil.h"

void selectionSort(int arr[], const int size) {
    int i = 0;
    while (i < size - 1 && arr[i] <= arr[i + 1]) i++;
    if (i >= size - 1) return;
    int minIndex = i;
    for (int j = i + 1; j < size; j++) if (arr[j] < arr[minIndex]) minIndex = j;
    if (minIndex != i) swap(arr, i, minIndex);
}

void bubbleSort(int arr[], const int size) {
    for (int j = 0; j < size - 1; j++) if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
}

void insertionSort(int arr[], const int size) { // TODO CURRENTLY BUBLE SORT WITH ONE SEARCH
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        if (arr[j] > key) {
            arr[j + 1] = arr[j];
            arr[j] = key;
            break;
        }
    }
}

void swap(int arr[], const int i, const int j) {
    const int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(const int arr[], const int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool isSorted(const int arr[], const int size) {
    for (int i = 1; i < size; i++) if (arr[i] < arr[i - 1]) return false;
    return true;
}