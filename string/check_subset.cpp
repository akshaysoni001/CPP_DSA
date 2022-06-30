#include<iostream>
#include<string>
using namespace std;



int main(){
	string s1 = "codingminutes";
	string s2 = "cinse";
	int k=0;
	int i=0;
	while(i<s1.length() and k<s2.length()){
		if(s1[i]==s2[k]){
			k++;
		}
		i++;
	}
	if(k==s2.length()){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}

	return 0;
}