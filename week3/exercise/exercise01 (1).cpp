#include <iostream>
using namespace std;

int firstIndex(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    int first = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == k) { 
            first = mid;
            right = mid - 1; 
        } else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

int lastIndex(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    int last = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == k) {
            last = mid;
            left = mid + 1; 
        } else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

int count_k(int arr[], int n, int k) { 
    int first = firstIndex(arr, n, k); 
    if (first == -1) {
        return 0;
    }
    int last = lastIndex(arr, n, k); 
    return last - first + 1;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k = 2;
    int count = count_k(arr, n, k); 
    cout << k << endl;
    return 0;
}
