#include <iostream>
#include <vector>

using namespace std;

int main(){
	int maxi,start,end,i = 0,curr,N,T;
	cin>>N>>T;
	int width[N];
	vector<int> ones,twos;
	curr = N;
	
	while(curr--){
		cin>>width[i];
		if(width[i] == 1) ones.push_back(i);
		else if(width[i] == 2) twos.push_back(i);
        i++;
	}

    
	int one_size = ones.size();
	int two_size = twos.size();
    
	while(T--){
        maxi = 0;
		cin>>start>>end;
		int flag = 0;

		for(int i = 0;i<N;i++){
			if(i>=one_size && i>=two_size){
				if(maxi == 0) flag = 1;
				break;
			}

			if(i<one_size && (ones[i]>=start && ones[i]<=end)){
				maxi = 1;
				break;
			}

			else if(i<two_size && (twos[i]>=start && twos[i]<=end)){
				maxi = 2;
			}
		}

		if(flag == 1) cout<<3<<endl;

		else cout<<maxi<<endl;
	}

	return 0;
}