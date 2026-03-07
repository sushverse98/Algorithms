#include<bits/stdc++.h>
using namespace std;

int SumN(int i, int N, int sum){
    if(i > N) return sum; 
    return SumN(i+1,N, sum += i);   
}

int main(){
    int n,sum = 0;
    cout<<"Enter value of n: ";
    cin>>n;
    int result = SumN(1,n, sum);
    cout << result;
}