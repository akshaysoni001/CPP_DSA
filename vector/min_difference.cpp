#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

pair<int,int> minDiff(vector<int> a, vector<int> b){
	pair<int,int> result;
	int mindiff=INT_MAX;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int n = min(a.size(),b.size());
	int i=0,j=0;
	while(i<n and j<n){
		int diff = abs(a[i]-b[j]);
		// if(diff==0) { j++; continue; }
		if(diff < mindiff and diff!=0){
			mindiff = diff;
			result.first = a[i];
			result.second = b[j];
		}
		if(a[i] < b[j]) { i++; }
		else { j++; }

	}
	return result;
}

int main(){
	// vector<int> a = {23,5,10,17,30};
	// vector<int> b = {26,134,135,14,19};

	vector<int> a = {23,5,10,117,5,30};
	vector<int> b = {26,134,135,124,10,19,100,120};

	pair<int,int> output = minDiff(a,b);
	cout<<output.first<<","<<output.second;
	cout<<endl;


	return 0;
}