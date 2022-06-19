#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwap(vector<int> arr){
	int n = arr.size();
	int ans=0;
	pair<int,int> ap[n];
	for(int i=0;i<n;i++){
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	// Sorting to get correct index
	sort(ap,ap+n);
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		int oldindices = ap[i].second;
		// getting cycle
		// if it is visited or on on corret possition already
		if(visited[i]==true or oldindices == i){
			continue;
		}

		// otherwise
		int node = i;
		int cycle = 0;
		while(!visited[node]){
			visited[node] = true;
			int next_pos = ap[node].second;
			node = next_pos;
			cycle++;
		}
		ans += (cycle-1);
	}
	return ans;
}


int main(){

	vector<int> arr = {5,4,3,1,2};
	cout<<minSwap(arr);

	return 0;
}