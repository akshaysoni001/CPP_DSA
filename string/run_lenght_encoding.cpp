#include <iostream>
#include <string>
using namespace std;

string compressed_string(const string &str){

	int cnt = 1;
	  string s;
	  s+=str[0];
	  int k=0;
	  for(int i=1;i<str.length();i++){
	  	if(str[i]==s[k]){
	  		cnt++;
	  	}
	  	else{
	  		s+=to_string(cnt);
	  		s+=str[i];
	  		k+=2;
	  		cnt=1;
	  	}



	  }
	  s+=to_string(cnt);
	  return s.length()>str.length() ? str :s;
}

int main(){
	string s = "abc";
	cout<<compressed_string(s);

	return 0;
}