
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int i,N,K,j = 0;
    long long curr,cost;
    cin>>N>>K;
    vector<long long> A;
    
    for(i=0;i<N;i++){
        cin>>curr;
        A.push_back(curr);
    }
    
    sort(A.begin(),A.end());
    
    cost = 0;
    int rem = N;
    
    while(rem > 0){
        for(i=0;i<K;i++){
            if(rem-i-1>=0) cost += (j+1)*A[rem-i-1];
        }
        rem = rem-K;
        j++;
    }
    
    cout<<cost<<endl;
    return 0;
}

