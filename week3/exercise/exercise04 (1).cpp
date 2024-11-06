
#include<iostream>

using namespace std;

int findMissing (int arr[],int n){

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left;
} 


int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missing = findMissing(arr, n);
    cout << "The missing number is: " << missing << endl;

    return 0;
}