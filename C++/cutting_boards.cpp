#include <iostream>
#include <set>
#include <cstdlib>
#define MAXI 1000000007

using namespace std;
/*
long long product(long long x,long long y){
	if(x == 1) return y%MAXI;
	else if(y == 1) return x%MAXI;

	if(y > x) return product(y,x)%MAXI;

	return (x + product(x,y-1)%MAXI)%MAXI;
}*/

int main(){
	long long T,M,N,curr;
	cin>>T;

	while(T--){
		cin>>M>>N;
		multiset<long long> X;
		multiset<long long> Y;
		set<long long>::iterator it;
		for(long long i = 1;i<M;i++){
			cin>>curr;
			X.insert(curr);
		}

		for(long long i = 1;i<N;i++){
			cin>>curr;
			Y.insert(curr);
		}

		long long sum = 0,xmax,ymax,xbars = 1,ybars = 1;

		while(!(X.empty() && Y.empty())){
            xmax = -100000;
            ymax = -100000;
            if(!X.empty()){
				it = X.end();
				it--;
				xmax = (*it);
            }
            if(!Y.empty()){
				it = Y.end();
				it--;
				ymax = (*it);
            }
			
			if(xmax > ymax){
				it = X.end();
				it--;
				X.erase(it);
				sum += xmax*ybars%MAXI;//product(xmax,ybars)%MAXI;
				sum = sum%MAXI;
                //cout<<xmax<<" "<<ybars<<endl;
				xbars++;
			}
			
			else{
				it = Y.end();
				it--;
				Y.erase(it);
				sum += ymax*xbars%MAXI;//product(ymax,xbars)%MAXI;
				sum = sum%MAXI;
                //cout<<ymax<<" "<<xbars<<endl;
				ybars++;	
			}
		}

		cout<<sum<<endl;
	}

	return 0;
}