#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int m = mid - left + 1;
    int n = right - mid;
    int arr1[m];
    int arr2[n];

    for(int i=0;i<m;i++){
        arr1[i] = arr[left+i];
    }

    for(int j=0;j<n;j++){
        arr2[j] = arr[mid+1+j];
    }

    int i=0,j=0,k=left;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            k++;
            i++;
        }else{
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }

    while(i < m){
        arr[k] = arr1[i];
        k++;
        i++;
    }

    while(j < n){
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) /2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    int arr[] = {5,2,8,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
