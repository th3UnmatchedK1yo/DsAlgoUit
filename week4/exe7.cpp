//22520585
//Vo Ha Minh Huy
//ex7
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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void hybridSort(int arr[], int n) {
    if (n <= 10) {
        insertionSort(arr, n);
    } else {
        mergeSort(arr, 0, n - 1);
    }
}

void generateRandomArray(int arr[], int n, int min = 1, int max = 10000) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void measureSortTime(void (*sortFunc)(int[], int), int arr[], int n, const string& sortName) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock(); 
    double duration = double(end - start) / CLOCKS_PER_SEC; 
    cout << sortName << " time for " << n << " elements: " << duration << " seconds" << endl;
}

int main() {
    srand(time(0)); 

    int sizes[] = {10, 50, 200};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Tạo mảng ngẫu nhiên
        int* arr = new int[n];
        generateRandomArray(arr, n);

 
        int* arrCopy = new int[n];
        std::copy(arr, arr + n, arrCopy); 
        measureSortTime(hybridSort, arrCopy, n, "Hybrid Sort");

        
        std::copy(arr, arr + n, arrCopy); 
        cout << "\nTesting Merge Sort for " << n << " elements:" << endl;
        measureSortTime(mergeSort, arrCopy, n, "Merge Sort");

        delete[] arr;
        delete[] arrCopy;
    }

    return 0;
}
