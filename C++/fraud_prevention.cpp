#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

vector<string> mystrtok(string arg){
	string curr = "";
	vector<string> retval;
	int start = 0;
	for(int i = 0;i<arg.length();i++){
		if(arg[i] == ','){
			curr = arg.substr(start,i-start);
			cout<<curr;
            retval.push_back(curr);
			curr = "";
			start = i+1;
		}
	}
	if(start!=arg.length()) retval.push_back(arg.substr(start));

	return retval;
}

string mychangecase(string arg){
	string retval = "";

	for(int i = 0;i<arg.length();i++) retval.push_back(tolower(arg[i]));

	return retval;
}

string filter_email(string arg){
	string retval = "";

	for(int i = 0;i<arg.length();i++){
		if(arg[i] != '.') retval.push_back(arg[i]);
		if(arg[i] == '@') break;
	}

	int first_plus = -1;
	int at_rate = -1;

	for(int i = 0;i<retval.length();i++){
		if(retval[i] == '+' && first_plus == -1) first_plus = i;
		if(retval[i] == '@') at_rate = i;
	}

	retval = retval.substr(0,first_plus) + retval.substr(at_rate);

	return retval;
}

string filter_address(string arg){
	string curr, retval = "";
	curr = arg;
	string abbr[5],full[5];
	abbr[0] = " St.";
	abbr[1] = " Rd.";
	abbr[2] = " CA";
	abbr[3] = " NY";
	abbr[4] = " IL";
	full[0] = " Street";
	full[1] = " Road";
	full[2] = " California";
	full[3] = " New York";
	full[4] = " Illinois";

	for(int j = 0;j<5;j++){
		int i = curr.find(abbr[j]);
	
		while(i != string::npos){
			if(i!=curr.length() - 4) retval = curr.substr(0,i) + full[j] + curr.substr(i+4);
			else retval = curr.substr(0,i) + full[j];

			curr = retval;
			i = curr.find(full[j]);
		}
	}
}

string filter_zip(string arg){
	string curr, retval = "";
	curr = arg;

	for(int i = 0;i<curr.length();i++){
		if(curr[i] != '-') retval.push_back(curr[i]);
	}

	return retval;
}

int main(){
	int curr, T;
	string str;
	cin>>T;
	curr = T;
	vector<string> order_id, deal_id, email, street, city, state, zip_code, credit_card;
	map<vector<string>,pair<string,string> > M1, M2;
	map<vector<string>,pair<string,string> >::iterator it;
	vector<string> v,fraudulent;
	int flag = 0;

	while(curr--){
		getline(cin,str);
		vector<string> v = mystrtok(str);
        cout<<v.size()<<endl;
		order_id.push_back(mychangecase(v[0]));
		deal_id.push_back(mychangecase(v[1]));
		email.push_back(mychangecase(v[2]));
		street.push_back(mychangecase(v[3]));
		city.push_back(mychangecase(v[4]));
		state.push_back(mychangecase(v[5]));
		zip_code.push_back(mychangecase(v[6]));
		credit_card.push_back(mychangecase(v[7]));
	}
        
	curr = T - 1;

	while(curr--){
		email[curr] = filter_email(email[curr]);
		street[curr] = filter_address(street[curr]);
		city[curr] = filter_address(city[curr]);
		state[curr] = filter_address(state[curr]);
		zip_code[curr] = filter_zip(zip_code[curr]);
		v.clear();
		v.push_back(email[curr]);
		v.push_back(deal_id[curr]);
		it = M1.find(v);
		int is_fraud = 0;
		if(it != M1.end()){
			if(it->second.second != credit_card[curr]){
				if(fraudulent.empty()) fraudulent.push_back(it->second.first);
				fraudulent.push_back(deal_id[curr]);
				is_fraud = 1;
			}
		}

		else{
			pair<string,string> p1 = make_pair(deal_id[curr],credit_card[curr]);
			M1.insert(pair<vector<string>,pair<string,string> >(v,p1));
		}
		if(!is_fraud){
			v.clear();
			v.push_back(street[curr]);
			v.push_back(city[curr]);
			v.push_back(state[curr]);
			v.push_back(zip_code[curr]);
			v.push_back(deal_id[curr]);
			it = M2.find(v);
			if(it!=M2.end()){
				if(it->second.second != credit_card[curr]){
					if(fraudulent.empty()) fraudulent.push_back(it->second.first);
					fraudulent.push_back(deal_id[curr]);
					is_fraud = 1;
				}
			}

			else{
				pair<string,string> p2 = make_pair(deal_id[curr],credit_card[curr]);
				M2.insert(pair<vector<string>,pair<string,string> >(v,p2));
			}
		}	
	}
    for(int i = 0;i<fraudulent.size()-1;i++) cout<<fraudulent[i]<<",";
    cout<<fraudulent[fraudulent.size()-1];
    
	return 0;
}