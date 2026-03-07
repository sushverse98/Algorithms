#include<bits/stdc++.h>
using namespace std;

void allSubset(int index, int arr[], int n, vector<int> &result){
    if(index == n){
        for(auto x:result){
            cout<<x<<" ";
        }
        if(result.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    //pick the element
    result.push_back(arr[index]);
    allSubset(index+1,arr,n,result);
    result.pop_back();

    //do not pick the element of that index
    allSubset(index+1,arr,n,result);
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;
    vector<int>result;

    allSubset(index,arr,n,result);

    return 0;
}