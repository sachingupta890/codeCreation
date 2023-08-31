#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n, int digit) {
    int output[n];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(arr[i] / digit) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
int max_value(int arr[],int n){
    //step 1 find the max element in the array
    int maxi = arr[0];
    for(int i = 0; i<n; i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

void radixSort(int arr[], int n) {
    int maxVal = max_value(arr, n);
    int digit = 1;
    while (maxVal / digit > 0) {
        countingSort(arr, n, digit);
        digit *= 10;
    }
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
