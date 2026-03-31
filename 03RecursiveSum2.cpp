#include<bits/stdc++.h>
using namespace std;

int recursiveSum(int n){
    if(n == 0) return 0;
    return n + (recursiveSum(n-1));
}

int main(){
    int n,result;
    cout<<"enter the value of n: ";
    cin>>n;

    result = recursiveSum(n);
    cout<<result;

}