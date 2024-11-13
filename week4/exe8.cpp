//22520585
//Vo Ha Minh Huy
//ex8
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void hybridSort(int arr[], int low, int high) {
    if (high - low + 1 <= 10) {
        insertionSort(arr + low, high - low + 1);
    } else {
        int pi = partition(arr, low, high);
        hybridSort(arr, low, pi - 1);
        hybridSort(arr, pi + 1, high);
    }
}

void Input(int arr[], int n) {
    cout << "Enter " << n << " numbers for the array: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

long long measureSortTime(void (*sortFunc)(int[], int, int), int arr[], int low, int high, const string& sortName) {
    clock_t start = clock();
    sortFunc(arr, low, high);
    clock_t end = clock();
    long long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;
    cout << sortName << " time for " << high - low + 1 << " elements: " << duration << " microseconds" << endl;
    return duration;
}

int main() {
    srand(time(0));

    int sizes[] = {10, 50, 100, 500, 1000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        int* arr = new int[n];
        Input(arr, n);

        int* arrCopy = new int[n];

        int* arrCopy = new int[n];
        copy(arr, arr + n, arrCopy);

        cout << "\nTesting Hybrid Sort for " << n << " elements:" << endl;
        measureSortTime(hybridSort, arrCopy, 0, n - 1, "Hybrid Sort");

        copy(arr, arr + n, arrCopy);
        cout << "\nTesting Quick Sort for " << n << " elements:" << endl;
        measureSortTime(quickSort, arrCopy, 0, n - 1, "Quick Sort");

        delete[] arr;
        delete[] arrCopy;
    }

    return 0;
}
