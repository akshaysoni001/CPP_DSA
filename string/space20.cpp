#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void replace_space(char *s){
	int spaces = 0;
	
	// Find No of Spaces
	for(int i=0;i!='\0';i++){
		if(s[i]==' '){ spaces++; }
	}

	// Replacing Spaces
	int idx = s.strlen(s) + 2*spaces;
	s[idx]='\0';
	
	for(int i=strlen(s)-1;i>=0;i--){
		if(s[i]==' '){
			s[idx-1] = '0';
			s[idx-2] = '2';
			s[idx-3] = '%';
			idx = idx - 3;
		}
		else{
			s[idx-1] = s[i];
			idx--;
		}
	}

}


int main(){
	char input[1000] = "hello world, how are you?";
	replace_space(input);
	for(auto ch: input){
		cout<<ch<<"-";
	}
	return 0;
}