#include <iostream>

using namespace std;

int adjacency[101][101],parent[101];

void init(){
    int i,j;
    
    for(i=0;i<101;i++){
        parent[i] = 0;
        for(j=0;j<101;j++){
            adjacency[i][j] = 0;
        }
    }
    
}

int totalchildren(int v){
    int i,count = 1;

    for(i=0;i<101;i++){
        if(adjacency[v][i] == 1) count += totalchildren(i);
    }
    
    return count;
}

int even_children(int v){
    int count = 0,i;
    
    for(i=0;i<101;i++){
        if(adjacency[v][i] == 1){
            if(totalchildren(i)%2 == 0) count++;
        }
    }
    
    return count;
}

int edges(int v){
    int count = 0,i;
    count = even_children(v);
    
    for(i=0;i<101;i++){
        if(adjacency[v][i] == 1) count+=edges(i);
    }
    
    return count;
}

int main(){
    int V,V1,V2,E,number,i;
    cin>>V>>E;
    
    for(i=0;i<E;i++){
        cin>>V1>>V2;
        if(parent[V1] == 0 && parent[V2] == 0){
            if(V1<V2){
                adjacency[V1][V2] = 1;
                parent[V2] = 1;
            }
            else{
                adjacency[V2][V1] = 1;
                parent[V1] = 1;
            }
        }
        else{
            if(parent[V1] != 0){
                adjacency[V1][V2] = 1;
                parent[V2] = 1;
            }
            else{
                adjacency[V2][V1] = 1;
                parent[V1] = 1;
            }
        }
    }
    
    int root;
    
    for(i=1;i<V+1;i++){
        if(parent[i]==0) root = i;
    }
    
    number = edges(root);
    
    cout<<number<<endl;
    return 0;
}