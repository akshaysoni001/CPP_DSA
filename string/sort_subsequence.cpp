#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	if(a.length()==b.length()){
		return b > a;
	}
	return a.length() > b.length();
}

void sortSubsequence(string s, vector<string> &v, string o){
	// base case
	if(s.length()==0){
		v.push_back(o);
		return;
	}

	// Rec case
	// includeFirstChar
	char ch = s[0];
	string reduced_string = s.substr(1);
	sortSubsequence(reduced_string,v,o+ch);

	// Exclude FirstChar
	sortSubsequence(reduced_string,v,o);

}

int main(){
	string s;
	cin>>s;
	vector<string> v;
	string o = "";
	sortSubsequence(s,v,o);
	sort(v.begin(),v.end(),cmp);
	for(auto x: v){
		cout<<x<<",";
	}
	cout<<endl;
	return 0;
}