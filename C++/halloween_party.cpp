#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	
	while(T--){
		long long K;
		cin>>K;
		long long curr = K/2;
		long long curr2 = K - curr;
		cout<<curr*curr2<<endl;
	}

	return 0;
}