#include <iostream>
#include <math.h>

using namespace std;

int main(){
	string str;
	cin>>str;
	int len = str.length();
	float root = sqrt(len);
	int maxi = root,mini = root;
	
	if(mini < root) maxi++;

	if(mini*maxi < len) mini++;

	char encrypted[mini][maxi];

	for(int i = 0;i<mini;i++) for(int j = 0;j<maxi;j++) encrypted[i][j] = ' ';
	
	int curr = 0;
	
	for(int i = 0;i<mini;i++){
		
		for(int j = 0;j<maxi;j++){
			if(curr == len) break;
			encrypted[i][j] = str[curr];
            curr++;
		}

		if(curr == len) break;
	}

	for(int j = 0;j<maxi;j++){
		for(int i = 0;i<mini;i++){
			if(encrypted[i][j] != ' ') cout<<encrypted[i][j];
		}
		cout<<" ";
	}

	return 0;
}