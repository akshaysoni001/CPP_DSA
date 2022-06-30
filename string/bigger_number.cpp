#include<iostream>
#include<vector>
#include<cmath>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	int al = trunc(log10(a)) + 1;
	 int bl = trunc(log10(b)) + 1;
	 if(al==bl){ return a > b; }
	 return to_string(a)[0] > to_string(b)[0];
}

string concatenate(vector<int> numbers){

	sort(numbers.begin(),numbers.end(),compare);
	string s;
	for(int x: numbers){
		s = s + to_string(x);
	}
	return s;


}
int main(){

	vector<int> v = {10,200,30,11,1,2,3};
	// string s = concatenate(v);
	// cout<<s;
	bool ans = "27" > "26"; //11001, 11010
	cout<<ans;
	return 0;
}