#include <iostream>
#include <set>

using namespace std;

set<long long> s;

void init(){
	long long n = 0,a = 1,b = 1;
	while(n<35){
		s.insert(a);
		s.insert(b);
		a+=b;
		b+=a;
		n++;
	}
}

int main(){
	init();
	long long T,N;
	cin>>T;
	while(T--){
		cin>>N;
		if(s.count(N) != 0) cout<<"IsFibo"<<endl;
		else cout<<"IsNotFibo"<<endl;
	}
	return 0;
}