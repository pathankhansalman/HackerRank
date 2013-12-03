#include <iostream>
#include <math.h>

using namespace std;

int ADJ[101][101],x_ij[101][101],set[101],nsets = 0;

void init(){
    int i,j;
    
    for(i=0;i<101;i++){
        set[i] = 1;
        for(j=0;j<101;j++){
            ADJ[i][j] = 0;
        }
    }
}

void filladj(int p,int n){
    int i,j;
    
    for(i=1;i<n+1;i++){
        for(j=i+1;j<n+1;j++){
            if(x_ij[i][j]>=p) ADJ[i][j] = 1;
        }
    }
}

int checkloop(int n){
    int i,j;
    nsets = 0;
    int max = 0;
    
    for(i=1;i<n+1;i++){
        for(j=i+1;j<n+1;j++){
            if(ADJ[i][j] == 1){
                if(set[i] == set[j]){
                    set[j]++;
                    if(set[j]>max) max = set[j];
                }
            }
        }
    }
    
    nsets = max;
    int A[max + 1];
    A[0] = 0;
    int maxs = 0,sum = 0;
        
    for(i=1;i<=max;i++){
        A[i] = 0;
        for(j=1;j<n+1;j++){
            if(set[j] == i) A[i]++;
        }
        if(A[i]>maxs) maxs = A[i];
        sum= sum + A[i];
    }
    
    if(maxs<=(sum - maxs)) return 1;
    else return 0;
}

int main(){
    int N,i,j;
    cin>>N;
    int A[N+1];
    
    for(i=1;i<N+1;i++){
        cin>>A[i];
    }
    
    int max_x_ij = 0;
    
    for(i=1;i<N+1;i++){
        for(j = i + 1;j<N+1;j++){
            x_ij[i][j] = A[i] ^ A[j];
            if(x_ij[i][j] > max_x_ij) max_x_ij = x_ij[i][j];
        }
    }
    
    int gpl2 = 0,curr = max_x_ij;
    
    while(curr>2){
        curr = curr / 2;
        gpl2++;
    }
    
    while(1){
        int p = pow(2,gpl2);
        init();
        filladj(p,N);
        if(checkloop(N)){
            cout<<gpl2<<endl;
            break;
        }
        gpl2--;
    }
    
    return 0;

}