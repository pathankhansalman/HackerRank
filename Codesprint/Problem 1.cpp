#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

multiset<long long> fib;

void init(){
    long long a = 0,b = 1;
    fib.insert(a);
    fib.insert(b);
    while(1){
        a = a+b;
        b = a+b;
        fib.insert(a);
        fib.insert(b);
        if(b>10000000000) break;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    init();
    while(T--){
        long long N;
        cin>>N;
        if(fib.count(N) == 0) cout<<"IsNotFibo"<<endl;
        else cout<<"IsFibo"<<endl;
    }
    return 0;
}
