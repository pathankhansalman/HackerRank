#include <iostream>
#define MAXI 1000007

using namespace std;

int A[1000001];

void sieve(){
    long long i,j;
    
    for(i=0;i<1000001;i++) A[i] = 0;
    
    A[0] = 1;
    A[1] = 1;
    
    for(i=2;i<1000001;i++){
        if(A[i] == 0){
            for(j = i; i*j <1000001;j++){
                A[i*j] = 1;
            }
        }
    }
}

int main(){
    long long i,N,count,product = 1,prev;
    double curr;
    cin>>N;
    sieve();
    
    for(i=0;i<=N;i++){
        curr = N;
        count = 0;
        if(A[i]==0){
            while(curr/i>=1){
                count = count + (curr/i);
                curr = curr/i;
            }
        }
        product = (product%MAXI) * ((2*count + 1)%MAXI);
    }
    
    if(N!=1) cout<<product%MAXI<<endl;
    else cout<<"0"<<endl;
    
    return 0;
}