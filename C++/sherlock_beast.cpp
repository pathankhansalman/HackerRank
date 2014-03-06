#include <iostream>

using namespace std;

string threes(int arg){
	char c = '3';
	string retval = "";
	while(arg--) retval.push_back(c);

	return retval;
}

string fives(int arg){
	char c = '5';
	string retval = "";
	while(arg--) retval.push_back(c);

	return retval;
}

int main(){
	int curr,T,N;
	cin>>T;
	
	while(T--){
		cin>>N;
		if(N%3 == 0) cout<<fives(N)<<endl;
		else{
			curr = N;
			while(!(curr%3 == 0)){
				if(curr<0) break;
				curr-=5;
			}
			if(curr<0) cout<<"-1"<<endl;
			else cout<<fives(curr)<<threes(N-curr)<<endl;
		}
	}

	return 0;
}