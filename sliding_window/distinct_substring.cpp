#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <climits>
using namespace std;

string smallestWindow(string s){
	int FS[256] = {0};
	int cnt=0;
	unordered_map<char,int> m;
	
	for(int i=0;i<s.length();i++){
		char ch = s[i];
		if(!m.count(ch)){
			m[ch]=1;
		}
	}
	cout<<"Distinct Size "<<m.size()<<endl;

	int start = 0;
	int start_idx = -1;
	int window_size=0;
	int min_so_far=INT_MAX;

	for(int i=0;i<s.length();i++){
		char ch = s[i]; 
		FS[ch]++;
		if(FS[ch] and FS[ch] == 1 ){
			cnt++;
		}

		// contracting string
		if(cnt == m.size()){
			
			while(FS[s[start]] == 0 or FS[s[start]] > 1){
				FS[s[start]]--;
				start++;
			}
			window_size = i - start + 1;
			cout<<s.substr(start,window_size)<<endl;
			cout<<"windowSize- "<<window_size<<"min_so_far- "<<min_so_far<<endl;
			if(window_size < min_so_far){
				min_so_far = window_size;
				start_idx = start;
			}

		}

	}
	if(start_idx==-1){ return "No String Found!!"; }
	return s.substr(start_idx,min_so_far);
}

int main(){
	string s;
	cin>>s;
	cout<<smallestWindow(s);

	return 0;
}