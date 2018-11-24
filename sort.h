#pragma once
void insertionSort(bool(*compare)(Student*, Student*));

void selectionSort(bool(*compare)(Student*, Student*));

void bubbleSort(bool(*compare)(Student*, Student*));

void mergeSort(bool(*compare)(Student*, Student*), int, int);

void quickSort(bool(*compare)(Student*, Student*), int, int);

void heapSort(bool(*compare)(Student*, Student*));
