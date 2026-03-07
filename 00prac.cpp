#include<bits/stdc++.h>
using namespace std;

int printN(int i,int sum){
    if(i < 1) return sum;
    return printN(i-1, sum += i);
}

int main(){
    int n,sum = 0;
    cout<<"Enter value of n: ";
    cin>>n;
    int result = printN(n,sum);
    cout << result;
}