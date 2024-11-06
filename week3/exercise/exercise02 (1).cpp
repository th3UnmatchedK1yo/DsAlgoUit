#include <iostream>

#include<cmath>
using namespace std;


int stepSize(int arr[],int n, int step,int currentPos, int k){
    if (arr[currentPos]>k){
        return max(1,step/2);
    }else if (arr[currentPos]<k){
        return min(step*2,(int)sqrt(n));
    }
    return step;
}

int jumpSearch (int arr[],int n, int k, int initial){
    
    int step=initial;
    int prev=0;
    while(arr[min(step,n)-1]<k){
        prev=step;
        step+=stepSize(arr,n,step,min(step,n)-1,k);
        if(prev>=n){
            return -1;
        }
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == k) return i;
    }
    return -1;

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
    int k = 15;
    int initialStep = sqrt(n);  

    int index = jumpSearch(arr,n, k, initialStep);
    if (index != -1) {
        cout << "The element " << k << " is found at index " << index << "." << endl;
    } else {
        cout << "The element " << k << " is not found in the array." << endl;
    }

    return 0;
}