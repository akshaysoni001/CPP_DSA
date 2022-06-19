#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// 2 Loops but time complexity is O(N), bz second loop also iterating thorugh i
pair<int,int> subArraySort(vector<int> &arr){
	int n = arr.size();
	int sidx = INT_MAX,eidx=INT_MIN;
	for(int i=1;i<n;i++){
		if(arr[i] < arr[i-1]){
			sidx = min(sidx, i-1);
			while(arr[i] > arr[i+1])
			{
				i++;
			}
			eidx = max(eidx,i);
		}
	}
	if(sidx==n){ return {-1,-1}; }
	return {sidx,eidx};
}



int main(){
	vector<int> arr = {2,3,1,8,10,9,15};
	pair<int,int> sort_idx = subArraySort(arr);
	 cout<<sort_idx.first<<" and "<<sort_idx.second<<endl;


	return 0;
}