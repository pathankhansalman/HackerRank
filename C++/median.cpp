
#include <iostream>
#include <set>
#include <cstdlib>
#define DEBUG 0

using namespace std;

multiset<long long> minset,maxset;
multiset<long long>::iterator it;
int flag = 0;

void adjust(){
	long long val;

	if(!minset.empty()){

		if(!maxset.empty()){

			if(maxset.size() > minset.size()){
				it = maxset.begin();
				val = *it;
				maxset.erase(it);
				minset.insert(val);
				adjust();
			}

			else if(minset.size() - maxset.size() > 1){
				it = minset.end();
				it--;
				val = *it;
				minset.erase(it);
				maxset.insert(val);
				adjust();
			}
		}

		else{

			if(minset.size() > 1){
				it = minset.end();
				it--;
				val = *it;
				minset.erase(it);
				maxset.insert(val);
				adjust();
			}
		}
	}

	else{
		if(!maxset.empty()){
			it = maxset.begin();
			val = *it;
			maxset.erase(it);
			minset.insert(val);
			adjust();
		}
	}
}

double median(char c,long long x){
	double retval;

	if(DEBUG){
		for(it = minset.begin();it!=minset.end();it++) cout<<*it<<" ";
		cout<<":";
		for(it = maxset.begin();it!=maxset.end();it++) cout<<*it<<" ";
		cout<<endl;
	}

	if(c == 'r'){

		if(minset.empty() && maxset.empty()){
            flag++;
            return -1;
        }

		else if(minset.empty()){

			if(maxset.count(x) == 0){
                flag++;
                return -1;
            }

			else{
				// TODO - Done
				it = maxset.find(x);
				if(it != maxset.end()) maxset.erase(it);
			}
		}

		else if(maxset.empty()){

			if(minset.count(x) == 0){
                flag++;
                return -1;
            }

			else{
				// TODO - Done
				it = minset.find(x);
				if(it != minset.end()) minset.erase(it);
			}
		}

		else if(minset.count(x) == 0 && maxset.count(x) == 0){
            flag++;
            return -1;
        }

		else{
			// TODO - Done
			if(minset.count(x) != 0){
				it = minset.find(x);
				if(it != minset.end()) minset.erase(it);
			}

			else{
				it = maxset.find(x);
				if(it != maxset.end()) maxset.erase(it);
			}
		}
		adjust();
	}

	else if(c == 'a'){
		it = maxset.begin();
		if(*it <= x) maxset.insert(x);
		else minset.insert(x);
		adjust();
	}

	if(minset.empty()){
            flag++;
            return -1;
    }

	else{// TODO

		if(minset.size() > maxset.size()){
			it = minset.end();
			it--;
			retval = *it;
		}

		else{
			it = minset.end();
			it--;
			retval = *it;
			it = maxset.begin();
			retval = (retval+(*it))/2;
		}
	}

	if(DEBUG){
		cout<<"Minset not empty"<<endl;

		for(it = minset.begin();it!=minset.end();it++) cout<<*it<<" ";
		cout<<":";

		for(it = maxset.begin();it!=maxset.end();it++) cout<<*it<<" ";
	}

	return retval;
}

int main(){
	char c;
	long long N,x,check;
	double retval;
	cin>>N;
	
	while(N--){
        flag = 0;
		cin>>c>>x;
		retval = median(c,x);

		if(retval == -1 && flag) cout<<"Wrong!"<<endl;
		else{
			check = (long long)retval;
			if(retval - check == 0) cout<<check<<endl;
			else if(retval<0 && check == 0) cout<<"-"<<check<<".5"<<endl;
            else cout<<check<<".5"<<endl;
		}
	}

	return 0;
}

