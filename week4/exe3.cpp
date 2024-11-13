
//22520585
//Vo Ha Minh Huy
//ex3

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

long long measureSortTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return (end - start);
}

int main() {
    int sizes[] = {100, 1000, 10000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int* intArr = new int[n];
        cout << "Nhập " << n << " phần tử cho mảng:\n";
        for (int j = 0; j < n; j++) {
            cin >> intArr[j];
        }

        int* intArrCopy = new int[n];
        cout << "\nSắp xếp " << n << " phần tử kiểu int:\n";
        copyArray(intArr, intArrCopy, n);
        long long bubbleTime = measureSortTime(bubbleSort, intArrCopy, n);
        cout << "Bubble Sort time: " << bubbleTime << " clock ticks" << endl;

        copyArray(intArr, intArrCopy, n);
        long long insertionTime = measureSortTime(insertionSort, intArrCopy, n);
        cout << "Insertion Sort time: " << insertionTime << " clock ticks" << endl;

        copyArray(intArr, intArrCopy, n);
        long long selectionTime = measureSortTime(selectionSort, intArrCopy, n);
        cout << "Selection Sort time: " << selectionTime << " clock ticks" << endl;

        delete[] intArr;
        delete[] intArrCopy;
    }

    return 0;
}
