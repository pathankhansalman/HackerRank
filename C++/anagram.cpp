#include <iostream>
#include <string>

using namespace std;

string myreverse(string arg){
	string retval = "";

	for(int i = arg.length() - 1;i>=0;i--) retval.push_back(arg[i]);

	return retval;
}

int mymin(int a, int b){
	if(a<b) return a;

	return b;
}

int mydiff(string a,string b){
	int retval = 0;

	for(int i = 0;i<a.length();i++){
		if(a[i] != b[i]) retval++;
	}

	return retval;
}

int main(){
	int T,count1[26],count2[26],min,sum;
	cin>>T;
	string str;
	char c = 'a';

	while(T--){
		for(int i = 0;i<26;i++) count1[i] = count2[i] = 0;

		cin>>str;
		
		if(str.length()%2 != 0){
			cout<<-1<<endl;
			continue;
		}

		string str1 = str.substr(0,str.length()/2);
		string str2 = str.substr(str.length()/2);

		for(int i = 0;i<str1.length();i++)	count1[str1[i] - (int)c]++;

		for(int i = 0;i<str2.length();i++)	count2[str2[i] - (int)c]++;

		for(int i = 0;i<26;i++){
			min = mymin(count1[i],count2[i]);
			count1[i]-=min;
			count2[i]-=min;
		}

		sum = 0;

		for(int i = 0;i<26;i++) sum+=count1[i];

		cout<<sum<<endl;
	}

	return 0;
}
