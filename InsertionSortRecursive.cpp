#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    // Base case
    if (n <= 1) return;

    // Sort first n-1 elements
    insertionSort(arr, n - 1);

    // Insert last element at correct position
    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

int main() {
    int arr[] = {5, 2, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}