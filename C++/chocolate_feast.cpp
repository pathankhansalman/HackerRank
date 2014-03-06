#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int N,C,M;
		cin>>N>>C>>M;

		int sum = 0;
		sum+=(N/C);

		int num = sum,num2;
		
		while(num>M){
			num2 = num;
			num = num2/M;
			num = num2 - (num*M);
		}

		sum+=num;

		cout<<sum<<endl;

	}
	return 0;
}