#include<iostream>
#include <algorithm>
using namespace std;


int main(){
	int n = 125;
	int hr = n/60;
	int min = n%60;
	string s_hr = to_string(hr);
	string s_min = to_string(min);
	if(s_min.length()==1){ s_min = '0'+s_min; }
	string output = s_hr + ":" + s_min;
	cout<<output;
}