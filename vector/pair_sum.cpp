#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// Brute Force complexity O(n^2)
vector<int> pairSum(vector<int> arr, int targetSum){
	int n = arr.size();
	vector<int> result;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==targetSum){
				result.push_back(arr[i]);
				result.push_back(arr[j]);
				break;
			}
		}
	}
	return result;


}

// Using Map => required map to store idx, if output need idx of elements
vector<int> OptPairSum(vector<int> arr,int targetSum){
	int n = arr.size();
	vector<int> result;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		int req_num = targetSum-arr[i];
		if(m.count(req_num)){  
			result.push_back(req_num);
			result.push_back(arr[i]);
			return result;
		}
		else{
			m[arr[i]] = i;
		}
	}

	return result;
}


// Using unordered set, if only pair is required
vector<int> OptPairSum_set(vector<int> v, int targetSum){
	vector<int> result;
	unordered_set<int> s;
	for(int i=0;i<v.size();i++){
		int req_num = targetSum - v[i];
		if(s.find(req_num)!=s.end()){
			result.push_back(v[i]);
			result.push_back(req_num);
			return result;
		}
		s.insert(v[i]);
	}
	return result;
}

int main(){
	vector<int> arr = {10,5,2,3,-6,9,11};
	int targetSum = 4;
	
	// Brute Force
	vector<int> output = pairSum(arr,targetSum);
	for(int x: output){
		cout<<x<<",";
	}

	// Opt using unorderedMap
	cout<<endl;
	vector<int> output_2 = OptPairSum(arr,targetSum);
	for(int x: output_2){
		cout<<x<<",";
	}

	// Opt using unordered_set
	cout<<endl;
	vector<int> output_3 = OptPairSum_set(arr,targetSum);
	for(int x: output_3){
		cout<<x<<",";
	}

	return 0;
}