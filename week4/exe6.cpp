//22520585
//Vo Ha Minh Huy
//ex6
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int findMax(int arr[], int n) {
    buildMaxHeap(arr, n);
    return arr[0];
}

int main() {
    srand(time(0));
    int n ;
    cout << "Enter " << n << " numbers for the array: \n";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum value: " << findMax(arr, n) << endl;

    return 0;
}