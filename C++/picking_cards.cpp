#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm> // binsearch
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <cstdlib> // abs(int),labs(int),llabs(int),min,max
#include <limits.h> // int_max,int_min,long_long_max,long_long_min

using namespace std;

#define read(x) cin>>x 
#define EPS 0.0000001
#define print(x) cout<<x<<endl
#define DEBUG 0
#define VI vector<long long> 
#define VS vector<string>
#define w(i) while(i--)
#define start int main()
#define max(a,b) (a)>(b)?(a):(b)
#define MAXI 1000000007

start{
	long long T;
	cin>>T;
	while(T--){
		long long N;
		cin>>N;
		long long A[N];
		for(int i = 0;i<N;i++) cin>>A[i];
		sort(A,A+N);
		//for(int i = 0;i<N;i++) cout<<A[i]<<" ";
		long long picked = 0,posn[N];
		for(int i = 0;i<N;i++){
			long long last = picked + 1;
			posn[i] = max((long long)0,last - A[i]);
			picked++;
		}
		long long count = 1;
		//for(int i = 0;i<N;i++) cout<<posn[i]<<" ";
		for(int i = 0;i<N;i++){
			count = (count*(posn[i]%MAXI))%MAXI;
		}
		cout<<count<<endl;
	}
	return 0;
}
