#include <iostream>
#include <string>
using namespace std;

int interpolationSearch(string arr[], int n, string& target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == target) return low;
            else return -1;
        }

        int pos = low + ((target.compare(arr[low])) * (high - low)) /
                        (arr[high].compare(arr[low]));

        if (pos < low || pos > high) return -1;
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    string arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string target = "cherry";

    int index = interpolationSearch(arr, n, target); 
    if (index != -1) {
        cout << "The element \"" << target << "\" is found at index " << index << "." << endl;
    } else {
        cout << "The element \"" << target << "\" is not found in the array." << endl;
    }

    return 0;
}
