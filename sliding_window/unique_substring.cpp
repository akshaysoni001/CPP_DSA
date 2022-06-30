#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


string unique_substring(string s){
	unordered_map<char,int> m;
	int i=0,j=0;
	int max_len=0,len=0;
	int sidx=0,eidx=0;
	int n = s.length();

	string result="";
	while(j<n){
		if(m.count(s[j]) and m[s[j]] >= i){			
			i = m[s[j]] + 1;
			len = j-i;
		}
		// cout<<"index of one unique_substring "<<i<<"-"<<j<<endl;
			
			m[s[j]] = j;
			j++;
			len++;
			
			if(len>max_len){
				max_len = len;
				sidx=i;
				eidx=j-1;
			}
	}
	for(int a=sidx;a<=eidx;a++){
		result+=s[a];
	}
	return s.substr(sidx,max_len);
}

int main(){
	string s = "prateekbhaiya";
	string sub_string = unique_substring(s);
	cout<<sub_string<<endl;



	return 0;
}