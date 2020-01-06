#pragma once

#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <time.h>
#include <tuple>
#include <string>
#include <vector>

// References:
// https://www.geeksforgeeks.org/
// http://www.cs.utah.edu/~ccasper/cs/flashsort.cpp

void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
int BinarySearch(int a[], int item, int low, int high);
void BinaryInsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void ShakerSort(int a[], int n);
void ShellSort(int arr[], int n);

void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);

void MergeArray(int a[], int na, int b[], int nb, int c[]);
void MergeSort(int a[], int n);

int Partition(int a[], int left, int right);
int Partition_r(int a[], int left, int right);
void QuickSort(int a[], int left, int right);

void CountingSort(int a[], int n);
int DigitOfMax(int a[], int n);
int Digit(int num, int k);
void Sort(int a[], int n, int k);
void CountingRadixSort(int a[], int n);

void ShowArr(int a[], int n);
long RunSort(int a[], int n, int type, bool show);

void FlashSort(int a[], int n);