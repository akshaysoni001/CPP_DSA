#include<iostream>
#include<vector>
using namespace std;

// Complexity O(N)
vector<pair<int, int>> housing(vector<int> p, int k){
	vector<pair<int,int>> result;
	int i=0,j=0;
	int cs = 0;
	int n = p.size();
	while(j<n){
		cs += p[j];
		j++;

		while(cs > k and i<j){
			cs -= p[i];
			i++;
		}

		if(cs == k){
			result.push_back(make_pair(i,j-1));
		}
	}


	return result;



}

int main(){
	vector<int> plot = {1,3,2,1,4,1,3,2,1,1,2};
	int k=8;
	vector<pair<int, int>> output = housing(plot,k);
	for(auto p: output){
		cout<<p.first<<","<<p.second<<endl;
	}

	return 0;
}