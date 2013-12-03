#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int maxim(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int N,i,j,old;
    cin>>N;
    int A[N];
    int S[N];
    vector<int> B;
    
    for(i=0;i<N;i++){
        cin>>A[i];
        S[i] = -1;
    }
    
    for(i=0;i<N-2;i++){
        if(A[i]>=A[i+1] && A[i+2]>=A[i+1]){
           S[i+1] = 1;
           B.push_back(i+1);
        }
    }
    
    if(A[0]<=A[1]){
        B.push_back(0);
        S[0] = 1;
    }
    
    if(A[N-1]<=A[N-2]){
        B.push_back(N-1);
        S[N-1] = 1;
    }
    
    int size = B.size();
    
    for(i=0;i<size;i++){
        for(j=0;j<B[i];j++){
            if(A[B[i] - j - 1] > A[B[i] - j]){
                old = S[B[i] - j - 1];
                S[B[i] - j - 1] = maxim(old,S[B[i] - j] + 1);
            }
            else if(A[B[i] - j - 1] == A[B[i] - j]){
                old = S[B[i] - j - 1];
                S[B[i] - j - 1] = maxim(old,1);
            }
            else break;
        }
        for(j=B[i];j<N - 1;j++){
            if(A[j + 1] > A[j]){
                old = S[j + 1];
                S[j + 1] = maxim(old,S[j] + 1);
            }
            else if(A[j + 1] == A[j]){
                old = S[j + 1];
                S[j + 1] = maxim(old,1);
            }
            else break;
        }
    }
    
    long long sum = 0;
    
    for(i=0;i<N;i++) sum += S[i];
    
    cout<<sum<<endl;
    
    return 0;
}