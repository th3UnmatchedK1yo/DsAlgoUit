#include <iostream>
#include <cstdlib> 
using namespace std;

int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 

    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }
    swap(arr[right], arr[storeIndex]); 
    return storeIndex;
}


int quicksort(int arr[], int left, int right, int k) {
    while (left <= right) {

        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(arr, left, right, pivotIndex);

        if (k == pivotIndex) {
            return arr[k];
        } else if (k < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1; 
        }
    }
    return -1; 
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k (1-based index for k-th smallest element): ";
    cin >> k;
    k--; 

    if (k < 0 || k >= n) {
        cout << "Invalid value of k." << endl;
        return -1;
    }

    int result = quicksort(arr, 0, n - 1, k);
    cout << "The " << (k + 1) << "th smallest element is: " << result << endl;

    return 0;
}
