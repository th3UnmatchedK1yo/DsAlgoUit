//22520585
//Vo Ha Minh Huy
//ex1 


#include <iostream>
#include<cmath>
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

void Input(int arr[], int n) {
    cout << "Enter " << n << " numbers for the array: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = source[i];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    Input(arr, n);

    int* arrCopy = new int[n];

    copyArray(arr, arrCopy, n);
    bubbleSort(arrCopy, n);
    cout << "Bubble Sort Done\n";

    copyArray(arr, arrCopy, n);
    insertionSort(arrCopy, n);
    cout << "Insertion Sort Done\n";

    copyArray(arr, arrCopy, n);
    selectionSort(arrCopy, n);
    cout << "Selection Sort Done\n";

    return 0;
}