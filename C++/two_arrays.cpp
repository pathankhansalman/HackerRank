#include <iostream>

using namespace std;

int main(){
	long long T;
	cin>>T;
	
	while(T--){
		long long N,K;
		cin>>N>>K;
		long long A[N],B[N];
		for(int i = 0;i<N;i++) cin>>A[i];
		for(int i = 0;i<N;i++) cin>>B[i];
		sort(A,A+N);
		sort(B,B+N);
		int flag = 0;
		for(int i = 0;i<N;i++){
			if(A[i] + B[N - i - 1] < K){
				flag = 1;
				break;
			}
		}

		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

	return 0;
}