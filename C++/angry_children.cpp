#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	int C[N];
	
	for(int i = 0;i<N;i++) cin>>C[i];

	sort(C,C+N);
	int min = 1000000;
	
	for(int i = 0;i<=N - K;i++) if(C[i+K - 1] - C[i] < min) min = C[i+K - 1] - C[i];
	
	cout<<min<<endl;

	return 0;
}