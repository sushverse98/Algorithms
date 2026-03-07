#include<bits/stdc++.h>
using namespace std;

int factorial(int i,int n, int answer){
    if(i > n) return answer;

    return factorial(i+1,n, answer * i);
}

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;

    int result = factorial(1,n,1);
    cout<<result;

    return 0;
}