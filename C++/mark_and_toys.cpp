#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long N,K;
	cin>>N>>K;
	long long P[N];
	
	for(int i = 0;i<N;i++) cin>>P[i];
	
	sort(P,P+N);
	int i = 0,sum = 0;
	
	while(K>0){
		K-=P[i];
		if(K>=0) sum++;
        i++;
	}

	cout<<sum<<endl;
	return 0;
}