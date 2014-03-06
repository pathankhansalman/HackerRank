#include <iostream>

using namespace std;

int main(){
	long long sum = 0,a,b,N,M;
	cin>>N>>M;
	
	while(M--){
		cin>>a>>b>>k;
		sum+=((b-a+1)*k);
	}

	long long avg = sum/N;
	double avg2 = sum/(N*1.);

	if(avg<avg2) cout<<avg<<endl;
	else cout<<avg-1<<endl;

	return 0;
}