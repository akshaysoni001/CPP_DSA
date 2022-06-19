#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> OptPairSum_set(vector<int> v, int targetSum, int begin){
	vector<vector<int>> final_result;
	vector<int> result;
	unordered_set<int> s;
	for(int i=begin;i<v.size();i++){
		int req_num = targetSum - v[i];
		if(s.find(req_num)!=s.end()){
			result.push_back(v[i]);
			result.push_back(req_num);

			final_result.push_back(result);
			result.clear();
			// return result;
		}
		s.insert(v[i]);
	}
	return final_result;
}

vector<vector<int>> tripletSum(vector<int> v, int targetSum){

	vector< vector<int>> result;
	unordered_set<int> s;
	for(int i=0;i<v.size();i++){
		int req_pair_sum = targetSum - v[i];
		vector<vector<int>> output = OptPairSum_set(v,req_pair_sum,i+1);
		for(auto v1: output){
			if(!v1.empty())
			{v1.push_back(v[i]);
				result.push_back(v1);}
		}

	}
	// sort(result.begin(),result.end());
	return result;

}

vector<vector<int>> tripletSumTwoPointer(vector<int> v, int targetSum){
	vector<vector<int>> result;
	int n=v.size();
	sort(v.begin(),v.end());
	for(int i=0;i<n-3;i++){

		int req_sum = targetSum - v[i];
		vector<int> subset;
		
		// Two Pointer Approch
		int j = i+1;
		int k = n-1;
		while(j<k){
			int sum = v[j]+v[k];
			if(sum > req_sum){
				k--;
			}
			else if( sum < req_sum){
				j++;
			}
			else{
				subset.push_back(v[i]);
				subset.push_back(v[j]);
				subset.push_back(v[k]);
				result.push_back(subset);
				subset.clear();
				j++;k--;
			}
		}

	}

	return result;
}


int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,15};
	int targetSum = 18;
	vector< vector<int>> output = tripletSum(v,targetSum);
	for(auto v1: output){
		for(int x: v1){
			cout<<x<<",";
		}
		cout<<endl;
	}

return 0;
}