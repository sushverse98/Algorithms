#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n <= 2) return n;
    return n * fact(n-1);
}

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;

    int result = fact(n);
    cout<<result;

    return 0;
}