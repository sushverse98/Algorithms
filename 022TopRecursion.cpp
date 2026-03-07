#include<bits/stdc++.h>
using namespace std;

void printN(int i, int N){
    if(i > N) return;
    cout<<N-i+1<<"\n"; 
    printN(i+1,N);
}

int main(){
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    printN(1,n);
}