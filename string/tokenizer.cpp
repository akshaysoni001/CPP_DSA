#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

char* customTokenizer(char input,char dilim){

	int idx;
	char token[1000];
	if(input!=NULL){
		idx=0;
	}

	for(;input[idx]!=dilim;idx++){
		token[idx] = input[idx];
	}

	
}


int main(){
	char input[1000];
	cin.getline(input, 1000);
	char* s1 = strtok(input," ");
	while(s1!=NULL){
		cout<<s1<<"-";
		s1 = strtok(NULL," ");
	}

	return 0;
}