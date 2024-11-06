#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

void linearSearch(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) break;
    }
}

void binarySearch(int arr[], int n, int target, int &comparisons) {
    int left = 0, right = n - 1;
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
}

void jumpSearch(int arr[], int n, int target, int &comparisons) {
    int step = sqrt(n);
    comparisons = 0;

    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return;
    }
    
    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == target) return;
    }
}

void runSearch(void (*searchFunc)(int[], int, int, int&), int arr[], int n, int target, const string& method) {  // sử dụng thao tác con trỏ hàm
    int comparisons = 0;

    clock_t start = clock();

    searchFunc(arr, n, target, comparisons);

    clock_t end = clock();

    double duration = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

    cout << method << " Search - Time: " << duration << " ms, Comparisons: " << comparisons << endl;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (sorted for binary and jump search): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    cin >> target;
    sort(arr, arr + n);

    runSearch(linearSearch, arr, n, target, "Linear");
    runSearch(binarySearch, arr, n, target, "Binary");
    runSearch(jumpSearch, arr, n, target, "Jump");

    return 0;
}
